#include <main.h>

// See https://gitlab.haskell.org/ghc/ghc-wasm-meta#custom-imports
#define IMPORTJS(module, jsname, cname, _cname) \
  void _cname(void *buf, uint32_t len) __attribute__((__import_module__(module),__import_name__(jsname)));\
  void cname(void *buf, uint32_t len) { _cname(buf, len); }

IMPORTJS("env", "displayHeader", displayHeader, _displayHeader)
IMPORTJS("env", "log", jslog, _jslog)
