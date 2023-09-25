import { File, PreopenDirectory, WASI } from "@bjorn3/browser_wasi_shim";
import _raylib from "./raylib"; // `raylib.js` is an auto-generated file created by emscripten
import {
  Heaps,
  ParamTypes,
  WASMInstance,
  bufToString,
  readArrayNonuniform,
  readArrayUint32,
  readBytes,
} from "./util";
import {
  EventFdReadWrite,
  EventRwFlags,
  EventType,
  Subscription,
  Event as WasiEvent,
} from "./wasi_patch";

window.addEventListener("load", () => {
  const args: string[] = []; // Command line arguments, not used
  const env: string[] = []; // Environment variables, not used

  // I copied and pasted this from the README of @bjorn3/browser_wasi_shim, but
  // logging directly to stdout in the Haskell code doesn't work (which is why
  // I made the `env.log` function). I am not sure what exactly these lines do.
  const fds = [
    new File([]).open(4), // stdin
    new File([]).open(4), // stdout
    new File([]).open(4), // stderr
    new PreopenDirectory(".", {}),
  ] as const;
  const wasi = new WASI(args, env, fds as any);

  // This is a shared memory object, it allows raylib and haskell to use the same memory addresses
  // This requires a couple headers enabled to work, see https://stackoverflow.com/a/65675390/17907758
  const memory = new WebAssembly.Memory({
    initial: 512,
    maximum: 1024,
    shared: true,
  });

  // These are some bootstrapping functions to initialize emscripten
  const Module: any = {
    preRun: [] as any[],
    postRun: [] as any[],
    print: (...args: string[]) => console.log(args.join(" ")),
    canvas: (function () {
      const canvas = document.getElementById("canvas");

      // As a default initial behavior, pop up an alert when webgl context is lost. To make your
      // application robust, you may want to override this behavior before shipping!
      // See http://www.khronos.org/registry/webgl/specs/latest/1.0/#5.15.2
      canvas.addEventListener(
        "webglcontextlost",
        function (e) {
          alert("WebGL context lost. You will need to reload the page.");
          e.preventDefault();
        },
        false
      );

      return canvas;
    })(),
    setStatus: (text: string) => {
      if (text) console.log("[WASM STATUS]", text);
    },
    totalDependencies: 0,
    monitorRunDependencies: (left: number) => {
      Module.totalDependencies = Math.max(Module.totalDependencies, left);
      Module.setStatus(
        left
          ? "Preparing... (" +
              (Module.totalDependencies - left) +
              "/" +
              Module.totalDependencies +
              ")"
          : "All downloads complete."
      );
    },
    wasmMemory: memory,
  };
  Module.setStatus("Downloading...");
  window.onerror = () => {
    Module.setStatus("Exception thrown");
  };

  (async () => {
    const raylib = await _raylib(Module); // Loads the raylib functions

    const wasm = await WebAssembly.compileStreaming(fetch("./haskell.wasm")); // Load the WASM file
    const heaps = new Heaps(); // A convenient class for accessing memory

    let inst: WASMInstance = (await WebAssembly.instantiate(wasm, {
      wasi_snapshot_preview1: {
        ...wasi.wasiImport,
        // Patch for stdout, see https://github.com/TristanCacqueray/browser_wasi_shim/commit/f34ed671b2ce2099983f365e6bb30d6f7fe7009c
        poll_oneoff: (
          in_ptr: number,
          out_ptr: number,
          nsubscriptions: number
        ) => {
          // in_: *const subscription
          // out: *mut event
          // nsubscription: usize
          let buffer = new DataView(inst.exports.memory.buffer);
          let in_ = Subscription.read_bytes_array(
            buffer,
            in_ptr,
            nsubscriptions
          );
          // console.log("poll_oneoff", in_, out_ptr, nsubscriptions);
          let events = [];
          for (let sub of in_) {
            if (sub.u.tag.variant == "fd_read") {
              let event = new WasiEvent();
              event.userdata = sub.userdata;
              event.error = 0;
              event.type = new EventType("fd_read");
              event.fd_readwrite = new EventFdReadWrite(
                BigInt(1),
                new EventRwFlags()
              );
              events.push(event);
            }
            if (sub.u.tag.variant == "fd_write") {
              let event = new WasiEvent();
              event.userdata = sub.userdata;
              event.error = 0;
              event.type = new EventType("fd_write");
              event.fd_readwrite = new EventFdReadWrite(
                BigInt(1),
                new EventRwFlags()
              );
              events.push(event);
            }
          }
          // console.log(events);
          WasiEvent.write_bytes_array(buffer, out_ptr, events);
          return events.length;
        },
      },

      // This object contains the functions that are used in the Haskell file
      env: {
        log: (ptr: number, len: number) => {
          heaps.useMemory(memory);
          console.log(bufToString(heaps, ptr, len));
        },
        // Calls a raylib function given its name, parameters (as an array of pointers),
        // and the sizes and types of those parameters
        callRaylibFunction: (
          namePtr: number,
          nameLen: number,
          paramsPtr: number,
          paramSizesPtr: number,
          paramTypesPtr: number,
          paramNum: number,
          returnSizeBytes: number,
          returnType: number
        ) => {
          heaps.useMemory(memory);
          const name = bufToString(heaps, namePtr, nameLen);
          const paramSizes = readArrayUint32(heaps, paramSizesPtr, paramNum);
          const paramTypes = readBytes(heaps, paramTypesPtr, paramNum);
          const params = readArrayNonuniform(
            heaps,
            paramsPtr,
            paramSizes,
            paramTypes
          );
          const result = raylib[name](...params);
          if (returnSizeBytes === 0) return;

          const ptr = raylib._malloc(returnSizeBytes);
          const signed = returnType === ParamTypes.SIGNED_INT;
          if (returnSizeBytes === 1)
            (signed ? heaps.HEAP8 : heaps.HEAPU8)[ptr] = result;
          else if (returnSizeBytes === 2)
            (signed ? heaps.HEAP16 : heaps.HEAPU16)[ptr / 2] = result;
          else if (returnSizeBytes === 4)
            (returnType === ParamTypes.FLOAT
              ? heaps.HEAPF32
              : signed
              ? heaps.HEAP32
              : heaps.HEAPU32)[ptr / 4] = result;
          else console.log("got unknown return size:", returnSizeBytes);

          return ptr;
        },
        // Frees a pointer; a pointer created with `raylib._malloc`cannot be
        // directly freed in haskell (with `Foreign.Marshal.Alloc.free`), so
        // this function is called from haskell instead.
        free: (ptr: number) => {
          raylib._free(ptr);
        },
        memory: memory,
      },
    })) as any;
    inst = { ...inst, exports: { ...inst.exports, memory } }; // WASI requires the module to export memory

    wasi.initialize(inst);
    inst.exports.hs_init(0, 0); // This must be called before calling any exported functions

    let state = inst.exports.startup(); // A pointer to the current state of the program
    raylib.setMainLoop(() => {
      if (inst.exports.shouldClose(state) === 1) {
        inst.exports.teardown(state);
        raylib.pauseMainLoop();
        return;
      }
      state = inst.exports.mainLoop(state);
    });
  })().catch((e) => console.log("got error:", e));
});
