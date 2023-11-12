#include "vec.h"
#include <memory.h>
#include <stdlib.h>

#define VEC_INITIAL_CAP 32

vec* vec_new(size_t data_size) {
    vec* vec;
    size_t needed = (sizeof *vec) + (data_size * VEC_INITIAL_CAP);
    vec = malloc(needed);
    if (vec == NULL) {
        return NULL;
    }
    memset(vec, 0, needed);
    vec->cap = VEC_INITIAL_CAP;
    vec->data_size = data_size;
    return vec;
}

int vec_push(vec** vec, void* data) {
    size_t len = (*vec)->len, cap = (*vec)->cap, data_size = (*vec)->data_size;
    size_t len_x_size = len * data_size;
    if (len == cap) {
        void* tmp;
        cap <<= 1;
        tmp = realloc(*vec, cap * data_size);
        if (tmp == NULL) {
            return -1;
        }
        *vec = tmp;
        memset((*vec)->data + len_x_size, 0, (cap - len) * data_size);
        (*vec)->cap = cap;
    }
    memcpy((*vec)->data + len_x_size, data, data_size);
    (*vec)->len += 1;
    return 0;
}

int vec_pop(vec* vec, void* out) {
    size_t pop_idx, pop_idx_x_size, data_size = vec->data_size;
    if (vec->len == 0) {
        return -1;
    }
    pop_idx = vec->len - 1;
    pop_idx_x_size = pop_idx * data_size;
    memcpy(out, vec->data + pop_idx_x_size, data_size);
    vec->len--;
    return 0;
}

void vec_free(vec* vec, FreeFn* fn) {
    if (fn) {
        size_t i, len = vec->len, data_size = vec->data_size;
        for (i = 0; i < len; ++i) {
            void* at = vec->data + (i * data_size);
            fn(at);
        }
    }
    free(vec);
}
