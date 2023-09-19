#include <main.h>

// See https://gitlab.haskell.org/ghc/ghc-wasm-meta#custom-imports
void _jslog(void *buf, uint32_t len) __attribute__((__import_module__("env"), __import_name__("log")));
void jslog(void *buf, uint32_t len) { _jslog(buf, len); }

void _jsfree(void *ptr) __attribute__((__import_module__("env"), __import_name__("free")));
void jsfree(void *ptr) { _jsfree(ptr); }

void *_callRaylibFunction(char *name, uint32_t nameLen, void **params, uint32_t *size_params, uint8_t *type_params, uint32_t num_params, uint32_t returnSizeBytes) __attribute__((__import_module__("env"), __import_name__("callRaylibFunction")));
void *callRaylibFunction(
  char *name, uint32_t nameLen, void **params, uint32_t *size_params, uint8_t *type_params, uint32_t num_params, uint32_t returnSizeBytes)
{
  return _callRaylibFunction(name, nameLen, params, size_params, type_params, num_params, returnSizeBytes);
}
