// Reads raw bytes from a section of memory
export function readBytes(heaps: Heaps, ptr: number, len: number): number[] {
  return Array.from(heaps.HEAPU8.subarray(ptr, ptr + len));
}

// Reads a string from WASM memory
export function bufToString(heaps: Heaps, ptr: number, len: number): string {
  return String.fromCharCode(...readBytes(heaps, ptr, len));
}

// Reads an array of uint32s from WASM memory
export function readArrayUint32(
  heaps: Heaps,
  ptr: number,
  numElements: number
): number[] {
  return Array.from(heaps.HEAPU32.subarray(ptr / 4, ptr / 4 + numElements));
}

// Reads an array of elements with varying sizes from WASM memory
export function readArrayNonuniform(
  heaps: Heaps,
  ptr: number,
  sizes: number[],
  types: number[]
): number[] {
  const items: number[] = [];
  let curPtr, size, type, signed;
  for (let i = 0; i < sizes.length; i++) {
    size = sizes[i];
    type = types[i];
    signed = type === ParamTypes.SIGNED_INT;
    curPtr = heaps.HEAPU32[ptr / 4];
    // 8 or 16 bit numbers are always integers, so we only need to check the sign
    // 32-byte numbers may be floats, so the type of number must be checked
    if (size === 1) items.push((signed ? heaps.HEAP8 : heaps.HEAPU8)[curPtr]);
    else if (size === 2)
      items.push((signed ? heaps.HEAP16 : heaps.HEAPU16)[curPtr / 2]);
    else if (size === 4)
      items.push(
        (type === ParamTypes.FLOAT
          ? heaps.HEAPF32
          : signed
          ? heaps.HEAP32
          : heaps.HEAPU32)[curPtr / 4]
      );
    else console.log("got unknown size", size);
    ptr += 4;
  }
  return items;
}

export enum ParamTypes {
  SIGNED_INT,
  UNSIGNED_INT,
  FLOAT,
}

export class Heaps {
  private _HEAPU8: Uint8Array;
  private _HEAPU16: Uint16Array;
  private _HEAPU32: Uint32Array;
  private _HEAPU64: BigUint64Array;
  private _HEAP8: Int8Array;
  private _HEAP16: Int16Array;
  private _HEAP32: Int32Array;
  private _HEAP64: BigInt64Array;
  private _HEAPF32: Float32Array;
  private _HEAPF64: Float64Array;
  private memory: WebAssembly.Memory;

  useMemory(memory: WebAssembly.Memory): void {
    this.memory = memory;
    this._HEAP8 = new Int8Array(this.memory.buffer);
    this._HEAP16 = new Int16Array(this.memory.buffer);
    this._HEAP32 = new Int32Array(this.memory.buffer);
    this._HEAP64 = new BigInt64Array(this.memory.buffer);
    this._HEAPU8 = new Uint8Array(this.memory.buffer);
    this._HEAPU16 = new Uint16Array(this.memory.buffer);
    this._HEAPU32 = new Uint32Array(this.memory.buffer);
    this._HEAPU64 = new BigUint64Array(this.memory.buffer);
    this._HEAPF32 = new Float32Array(this.memory.buffer);
    this._HEAPF64 = new Float64Array(this.memory.buffer);
  }

  get HEAPU8(): Uint8Array {
    return this._HEAPU8;
  }

  get HEAPU16(): Uint16Array {
    return this._HEAPU16;
  }

  get HEAPU32(): Uint32Array {
    return this._HEAPU32;
  }

  get HEAPU64(): BigUint64Array {
    return this._HEAPU64;
  }

  get HEAP8(): Int8Array {
    return this._HEAP8;
  }

  get HEAP16(): Int16Array {
    return this._HEAP16;
  }

  get HEAP32(): Int32Array {
    return this._HEAP32;
  }

  get HEAP64(): BigInt64Array {
    return this._HEAP64;
  }

  get HEAPF32(): Float32Array {
    return this._HEAPF32;
  }

  get HEAPF64(): Float64Array {
    return this._HEAPF64;
  }
}

export type WASMInstance = {
  exports: {
    memory: WebAssembly.Memory;
    _initialize: () => any;
    hs_init: (a: number, b: number) => void;
  } & HaskellExports;
};

export type HaskellExports = {
  startup: () => number;
  mainLoop: (state: number) => number;
  shouldClose: (state: number) => 0 | 1;
  teardown: (state: number) => void;
};
