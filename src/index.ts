import {
  WASI,
  File,
  OpenFile,
  PreopenDirectory,
} from "@bjorn3/browser_wasi_shim";
import {
  bufToString,
  readArrayUint32,
  WASMInstance,
  Heaps,
  readArrayNonuniform,
  readBytes,
  ParamTypes,
} from "./util";
import _raylib from "./raylib";

window.addEventListener("load", () => {
  const args: string[] = []; // Command line arguments, not used
  const env: string[] = []; // Environment variables, not used

  // I copied and pasted this from the README of @bjorn3/browser_wasi_shim, but
  // logging directly to stdout in the Haskell code doesn't work (which is why
  // I made the `env.log` function). I am not sure what exactly these lines do.
  const fds = [
    new OpenFile(new File([])), // stdin
    new OpenFile(new File([])), // stdout
    new OpenFile(new File([])), // stderr
    new PreopenDirectory(".", {}),
  ];
  const wasi = new WASI(args, env, fds);

  const memory = new WebAssembly.Memory({
    initial: 512,
    maximum: 1024,
    shared: true,
  });
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
    const raylib = await _raylib(Module);

    const wasm = await WebAssembly.compileStreaming(fetch("./haskell.wasm")); // Load the WASM file
    const heaps = new Heaps();
    let inst: WASMInstance = (await WebAssembly.instantiate(wasm, {
      wasi_snapshot_preview1: wasi.wasiImport,

      // This object contains the functions that are used in the Haskell file
      env: {
        log: (ptr: number, len: number) => {
          heaps.useMemory(memory);
          console.log(bufToString(heaps, ptr, len));
        },
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
        free: (ptr: number) => {
          raylib._free(ptr);
        },
        memory: memory,
      },
    })) as any;
    inst = { ...inst, exports: { ...inst.exports, memory } };

    wasi.initialize(inst);
    inst.exports.hs_init(0, 0); // This must be called before calling any exported functions

    inst.exports.startup();
    raylib.setMainLoop(() => {
      if (inst.exports.shouldClose() === 1) {
        inst.exports.teardown();
        raylib.pauseMainLoop();
        return;
      }
      inst.exports.mainLoop()
    });
  })();
});
