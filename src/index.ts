import {
  WASI,
  File,
  OpenFile,
  PreopenDirectory,
} from "@bjorn3/browser_wasi_shim";

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

(async () => {
  const wasm = await WebAssembly.compileStreaming(fetch("./haskell.wasm")); // Load the WASM file
  const inst: WASMInstance = (await WebAssembly.instantiate(wasm, {
    wasi_snapshot_preview1: wasi.wasiImport,

    // This object contains the functions that are used in the Haskell file
    env: {
      displayHeader: (ptr: number, len: number) => {
        document.write(
          `<h1>${bufToString(inst.exports.memory.buffer, ptr, len)}</h1>`
        );
      },
      log: (ptr: number, len: number) => {
        console.log(bufToString(inst.exports.memory.buffer, ptr, len));
      },
    },
  })) as any;
  wasi.initialize(inst);

  inst.exports.hs_init(0, 0); // This must be called before calling any exported functions

  // This calls the `test` function from the Haskell code when the button is clicked
  document
    .getElementById("clickme")
    .addEventListener("click", () => inst.exports.test());
})();

// Reads a string from WASM memory
function bufToString(buf: ArrayBuffer, ptr: number, len: number): string {
  return String.fromCharCode(
    ...Array.from(new Uint8Array(buf).slice(ptr, ptr + len))
  );
}

type WASMInstance = {
  exports: {
    memory: WebAssembly.Memory;
    _initialize: () => any;
    hs_init: (a: number, b: number) => void;
  } & HaskellExports;
};

type HaskellExports = {
  test: () => void;
}
