#ifndef __VEC_H__
#define __VEC_H__

#include <stddef.h>

typedef void FreeFn(void* a);

typedef struct {
    size_t len;
    size_t cap;
    size_t data_size;
    unsigned char data[];
} vec;

vec* vec_new(size_t data_size);
int vec_push(vec** vec, void* data);
int vec_pop(vec* vec, void* out);
void vec_free(vec* vec, FreeFn* fn);

#endif /*__VEC_H__*/
