#ifndef __VEC_DECLARE_H__

#define __VEC_DECLARE_H__

#include "internal/raw_vec.h"
#include "type.h"

#define VEC_DECLARE(vec, Type, capacity)                                       \
    VEC_DECLARE_TYPE(vec##_type, Type, capacity, (_, _))                       \
    VEC_DECLARE_COMMON(vec, Type, capacity, vec##_type)

#define VEC_DECLARE_WITH(vec, Type, capacity, vtype)                           \
    VEC_DECLARE_COMMON(vec, Type, capacity, vtype)

#define VEC_DECLARE_COMMON(vec_, Type, capacity, vtype)                        \
    typedef struct {                                                           \
        Type buf[capacity];                                                    \
        vec_raw vec;                                                           \
    } vec_;                                                                    \
    typedef struct {                                                           \
        vec_raw_iter it;                                                       \
    } vec_##_iter;                                                             \
    static inline vec_ vec_##_new(void) {                                      \
        vec_ self = {0};                                                       \
        self.vec = vec_raw_new(&self.buf, capacity);                           \
        return self;                                                           \
    }                                                                          \
    static inline void vec_##_destory(vec_* self) {                            \
        vec_raw_destory(&vtype, &self->vec);                                   \
    }                                                                          \
    static inline size_t vec_##_size(vec_* self) {                             \
        return vec_raw_size(&vtype, &self->vec);                               \
    }                                                                          \
    static inline size_t vec_##_capacity(vec_* self) {                         \
        return vec_raw_capacity(&vtype, &self->vec);                           \
    }                                                                          \
    static inline bool vec_##_empty(vec_* self) {                              \
        return vec_raw_empty(&vtype, &self->vec);                              \
    }                                                                          \
    static inline void vec_##_reserve(vec_* self, size_t new_capacity) {       \
        vec_raw_reserve(&vtype, &self->vec, new_capacity);                     \
    }                                                                          \
    static inline vec_##_iter vec_##_iter_new(vec_* self) {                    \
        return (vec_##_iter){vec_raw_iter_new(&vtype, &self->vec)};            \
    }                                                                          \
    static inline Type* vec_##_iter_get(const vec_##_iter* it) {               \
        return (Type*)vec_raw_iter_get(&vtype, &it->it);                       \
    }                                                                          \
    static inline bool vec_##_iter_next(vec_##_iter* it) {                     \
        return vec_raw_iter_next(&vtype, &it->it);                             \
    }                                                                          \
    static inline Type* vec_##_find(vec_* self, const Type* value) {           \
        return (Type*)vec_raw_find(&vtype, &self->vec, value);                 \
    }                                                                          \
    static inline Type* vec_##_at(const vec_* self, size_t index) {            \
        return (Type*)vec_raw_at(&vtype, &self->vec, index);                   \
    }                                                                          \
    static inline Type* vec_##_at_unchecked(const vec_* self, size_t index) {  \
        return (Type*)vec_raw_at_unchecked(&vtype, &self->vec, index);         \
    }                                                                          \
    static inline Type* vec_##_first(const vec_* self) {                       \
        return (Type*)vec_raw_first(&vtype, &self->vec);                       \
    }                                                                          \
    static inline Type* vec_##_back(const vec_* self) {                        \
        return (Type*)vec_raw_back(&vtype, &self->vec);                        \
    }                                                                          \
    static inline Type* vec_##_data(const vec_* self) {                        \
        return (Type*)vec_raw_data(&vtype, &self->vec);                        \
    }                                                                          \
    static inline void vec_##_clear(vec_* self) {                              \
        vec_raw_clear(&vtype, &self->vec);                                     \
        (*self).vec = vec_raw_new(self->buf, capacity);                        \
    }                                                                          \
    static inline void vec_##_push_back(vec_* self, const Type* value) {       \
        vec_raw_push_back(&vtype, &self->vec, value);                          \
    }                                                                          \
    static inline void vec_##_pop_back(vec_* self, Type* out) {                \
        vec_raw_pop_back(&vtype, &self->vec, out);                             \
    }                                                                          \
    static inline void vec_##_erase(vec_* self, size_t index) {                \
        vec_raw_erase(&vtype, &self->vec, index);                              \
    }

#endif /* __VEC_DECLARE_H__ */
