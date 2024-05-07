#ifndef __VEC_TYPE_H__

#define __VEC_TYPE_H__

#include "internal/base.h"
#include "internal/extract.h"
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    size_t align;
    void (*copy)(void* dst, const void* src);
    void (*dtor)(void* val);
    bool (*eq)(const void* needle, const void* candidate);
} vec_object_type;

typedef struct {
    void* (*alloc)(size_t size, size_t align);
    void* (*realloc)(void* array, size_t size, size_t align);
    void (*free)(void* array, size_t size, size_t align);
} vec_alloc_type;

typedef struct {
    const size_t capacity;
    const vec_object_type* obj;
    const vec_alloc_type* alloc;
} vec_type;

#define VEC_DECLARE_TYPE(vtype, Type, capacity, ...)                           \
    VEC_EXTRACT_RAW(modifiers, static, __VA_ARGS__)                            \
    inline void vtype##_default_copy(void* dst, const void* src) {             \
        memcpy(dst, src, sizeof(Type));                                        \
    }                                                                          \
    VEC_EXTRACT_RAW(modifiers, static, __VA_ARGS__)                            \
    inline bool vtype##_default_eq(const void* a, const void* b) {             \
        return memcmp(a, b, sizeof(Type)) == 0;                                \
    }                                                                          \
                                                                               \
    VEC_EXTRACT_RAW(modifiers, static, __VA_ARGS__)                            \
    const vec_object_type vtype##_object_type = {                              \
        sizeof(Type),                                                          \
        alignof(Type),                                                         \
        VEC_EXTRACT(obj_copy, vtype##_default_copy, __VA_ARGS__),              \
        VEC_EXTRACT(obj_dtor, NULL, __VA_ARGS__),                              \
        VEC_EXTRACT(obj_eq, vtype##_default_eq, __VA_ARGS__),                  \
    };                                                                         \
    VEC_EXTRACT_RAW(modifiers, static, __VA_ARGS__)                            \
    const vec_alloc_type vtype##_alloc_type = {                                \
        VEC_EXTRACT(alloc_alloc, vec_default_malloc, __VA_ARGS__),             \
        VEC_EXTRACT(alloc_realloc, vec_default_realloc, __VA_ARGS__),          \
        VEC_EXTRACT(alloc_free, vec_default_free, __VA_ARGS__),                \
    };                                                                         \
    VEC_EXTRACT_RAW(modifiers, static, __VA_ARGS__)                            \
    const vec_type vtype = {                                                   \
        capacity,                                                              \
        &vtype##_object_type,                                                  \
        &vtype##_alloc_type,                                                   \
    }

static inline void* vec_default_malloc(size_t size, size_t align) {
    void* p = malloc(size);
    VEC_CHECK(p != NULL, "malloc returned null");
    return p;
}

static inline void* vec_default_realloc(void* array, size_t size,
                                        size_t align) {
    void* p = realloc(array, size);
    VEC_CHECK(p != NULL, "realloc returned null");
    return p;
}

static inline void vec_default_free(void* array, size_t size, size_t align) {
    free(array);
}

#endif /* __VEC_TYPE_H__ */
