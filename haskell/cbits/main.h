#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

void jslog(void *buf, uint32_t len);
void jsfree(void *ptr);
void *callRaylibFunction(char *name, uint32_t nameLen, void **params, uint32_t *size_params, uint8_t *type_params, uint32_t num_params, uint32_t returnSizeBytes);

#endif