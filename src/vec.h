#ifndef __VEC_H__
#define __VEC_H__

#include <stddef.h>
#include <sys/types.h>

typedef void FreeFn(void* a);
typedef int CmpFn(void* a, void* b);

typedef struct {
    size_t len;
    size_t cap;
    size_t data_size;
    unsigned char data[];
} vec;

typedef struct {
    void* cur;
    void* next;
    ssize_t next_idx;
    ssize_t end_idx;
    vec* vec;
} vec_iter;

vec* vec_new(size_t data_size);
vec* vec_new_with_capacity(size_t data_size, size_t capacity);
int vec_push(vec** vec, void* data);
int vec_pop(vec* vec, void* out);
void* vec_get_at(vec* vec, size_t idx);
int vec_remove_at(vec* vec, size_t idx, void* out);
ssize_t vec_find(vec* vec, void* cmp_data, void* out, CmpFn* fn);
void vec_free(vec* vec, FreeFn* fn);

vec_iter vec_iter_new(vec* vec);
void vec_iter_next(vec_iter* iter);

#endif /*__VEC_H__*/
