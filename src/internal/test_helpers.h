#include "../internal/base.h"
#include "../type.h"
#include <algorithm>

template <typename T> struct DefaultEq {
    bool operator()(const T& a, const T& b) { return a == b; }
};

template <typename T, int Capacity, typename Eq> struct VecTypeWrapper {
    // clang-format off
  VEC_DECLARE_TYPE(vtype, T, Capacity,
    (modifiers, static constexpr),
    (obj_copy, [](void* dst, const void* src) {
      new (dst) T(*static_cast<const T*>(src));
    }),
    (obj_dtor, [](void* val) {
      static_cast<T*>(val)->~T();
    }),
    (obj_eq, [](const void* a, const void* b) {
      return Eq{}(*static_cast<const T*>(a), *static_cast<const T*>(b));
    }));
    // clang-format on
};

template <typename T, int Capacity, typename Eq = DefaultEq<T>>
constexpr const vec_type& VecType() {
    return VecTypeWrapper<T, Capacity, Eq>::vtype;
};

#define VEC_HELPERS(vec, Type)                                                 \
    VEC_INLINE_ALWAYS inline void push(vec& v, const Type& value) {            \
        vec##_push_back(&v, &value);                                           \
    }                                                                          \
    VEC_INLINE_ALWAYS inline Type* find(vec& v, const Type& value) {           \
        return vec##_find(&v, &value);                                         \
    }                                                                          \
    VEC_INLINE_ALWAYS inline Type* at(vec& v, size_t index) {                  \
        return vec##_at(&v, index);                                            \
    }                                                                          \
    VEC_INLINE_ALWAYS inline std::vector<Type> collect(vec& v) {               \
        std::vector<Type> res;                                                 \
        Type* data = vec##_data(&v);                                           \
        size_t size = vec##_size(&v);                                          \
        res.reserve(size);                                                     \
        for (size_t i = 0; i < size; ++i) {                                    \
            res.push_back(data[i]);                                            \
        }                                                                      \
        return res;                                                            \
    }
