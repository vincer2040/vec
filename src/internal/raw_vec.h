#ifndef __RAW_VEC_H__

#define __RAW_VEC_H__

#include "../type.h"
#include <stddef.h>

typedef struct {
    char* buf;
    size_t length;
    size_t capacity;
} vec_raw;

VEC_INLINE_ALWAYS static inline void vec_raw_insert(const vec_type* type,
                                                    vec_raw* self,
                                                    const void* value,
                                                    size_t index) {
    type->obj->copy(self->buf + (index * type->obj->size), value);
    self->length++;
}

static inline vec_raw vec_raw_new(void* buf, size_t capacity) {
    vec_raw self = {.buf = (char*)buf, .length = 0, .capacity = capacity};
    return self;
}

static inline void vec_raw_destory(const vec_type* type, vec_raw* self) {
    if (type->obj->dtor) {
        for (size_t i = 0; i < self->length; ++i) {
            type->obj->dtor(self->buf + i * type->obj->size);
        }
    }
    if (self->capacity != type->capacity) {
        type->alloc->free(self->buf, type->obj->size, type->obj->align);
    }
    self->length = self->capacity = 0;
}

static inline size_t vec_raw_size(const vec_type* type, vec_raw* self) {
    return self->length;
}

static inline size_t vec_raw_capacity(const vec_type* type, vec_raw* self) {
    return self->capacity;
}

static inline bool vec_raw_empty(const vec_type* type, vec_raw* self) {
    return self->length == 0;
}

static inline void vec_raw_reserve(const vec_type* type, vec_raw* self,
                                   size_t new_capacity) {
    if (new_capacity <= self->capacity) {
        return;
    }
    if (self->capacity == type->capacity) {
        char* old_buf = self->buf;
        self->buf = (char*)type->alloc->alloc(type->obj->size * new_capacity,
                                              type->obj->align);
        if (self->length != 0) {
            memcpy(self->buf, old_buf, self->length * type->obj->size);
        }
    } else {
        self->buf = (char*)type->alloc->realloc(
            self->buf, type->obj->size * new_capacity, type->obj->align);
    }
    self->capacity = new_capacity;
}

static inline void* vec_raw_find(const vec_type* type, const vec_raw* self,
                                 const void* value) {
    for (size_t i = 0; i < self->length; ++i) {
        void* element = self->buf + (i * type->obj->size);
        if (type->obj->eq(value, element)) {
            return element;
        }
    }
    return NULL;
}

static inline void* vec_raw_at(const vec_type* type, const vec_raw* self,
                               size_t index) {
    if (index >= self->length) {
        return NULL;
    }
    return self->buf + (index * type->obj->size);
}

static inline void* vec_raw_at_unchecked(const vec_type* type,
                                         const vec_raw* self, size_t index) {
    return self->buf + (index * type->obj->size);
}

static inline void* vec_raw_first(const vec_type* type, const vec_raw* self) {
    if (self->length == 0) {
        return NULL;
    }
    return self->buf;
}

static inline void* vec_raw_back(const vec_type* type, const vec_raw* self) {
    if (self->length == 0) {
        return NULL;
    }
    return self->buf + (self->length - 1) * type->obj->size;
}

static inline void* vec_raw_data(const vec_type* type, const vec_raw* self) {
    if (self->length == 0) {
        return NULL;
    }
    return self->buf;
}

static inline void vec_raw_push_back(const vec_type* type, vec_raw* self,
                                     const void* value) {
    if (VEC_UNLIKELY(self->length == self->capacity)) {
        if (VEC_UNLIKELY(self->capacity == type->capacity)) {
            char* old = self->buf;
            self->capacity <<= 1;
            self->buf = (char*)type->alloc->alloc(
                type->obj->size * self->capacity, type->obj->align);
            memcpy(self->buf, old, type->obj->size * self->length);
        } else {
            self->capacity <<= 1;
            self->buf = (char*)type->alloc->realloc(
                self->buf, self->capacity * type->obj->size, type->obj->align);
        }
    }
    vec_raw_insert(type, self, value, self->length);
}

static inline void vec_raw_clear(const vec_type* type, vec_raw* self) {
    if (type->obj->dtor) {
        for (size_t i = 0; i < self->length; ++i) {
            type->obj->dtor(self->buf + i * type->obj->size);
        }
    }
    if (VEC_LIKELY(type->capacity != self->capacity)) {
        type->alloc->free(self->buf, type->obj->size, type->obj->align);
    }
    self->length = 0;
}

static inline void vec_raw_pop_back(const vec_type* type, vec_raw* self,
                                    void* out) {
    if (self->length == 0) {
        return;
    }
    self->length--;
    memcpy(out, self->buf + self->length * type->obj->size, type->obj->size);
}

static inline void vec_raw_erase(const vec_type* type, vec_raw* self,
                                 size_t index) {
    if (index >= self->length) {
        return;
    }
    if (index == self->length - 1) {
        if (type->obj->dtor) {
            type->obj->dtor(self->buf + index * type->obj->size);
        }
        self->length--;
        return;
    }
    if (type->obj->dtor) {
        type->obj->dtor(self->buf + index * type->obj->size);
    }
    self->length--;
    memmove(self->buf + index * type->obj->size,
            self->buf + (index + 1) * type->obj->size,
            (self->length - index) * type->obj->size);
}

#endif /* __RAW_VEC_H__ */
