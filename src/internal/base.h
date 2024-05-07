#ifndef __VEC_BASE_H__

#define __VEC_BASE_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __clang__
#define VEC_IS_CLANG 1
#else
#define VEC_IS_CLANG 0
#endif

#if defined(__GNUC__)
#define VEC_IS_GCCISH 1
#else
#define VEC_IS_GCCISH 0
#endif

#define VEC_IS_GCC (VEC_IS_GCCISH && !VEC_IS_CLANG)

#ifdef __has_builtin
#define VEC_HAVE_CLANG_BUILTIN(x) __has_builtin(x)
#else
#define VEC_HAVE_CLANG_BUILTIN(x) 0
#endif

#ifdef __has_attribute
#define VEC_HAVE_GCC_ATTRIBUTE(x) __has_attribute(x)
#else
#define VEC_HAVE_GCC_ATTRIBUTE(x) 0
#endif

#if VEC_HAVE_CLANG_BUILTIN(__builtin_expect) || VEC_IS_GCC
#define VEC_LIKELY(cond) (__builtin_expect(false || (cond), true))
#define VEC_UNLIKELY(cond) (__builtin_expect(false || (cond), false))
#else
#define VEC_LIKELY(cond) (cond)
#define VEC_UNLIKELY(cond) (cond)
#endif

#if VEC_HAVE_GCC_ATTRIBUTE(always_inline)
#define VEC_INLINE_ALWAYS __attribute__((always_inline))
#else
#define VEC_INLINE_ALWAYS
#endif

#if VEC_HAVE_GCC_ATTRIBUTE(noinline)
#define VEC_INLINE_NEVER __attribute__((noinline))
#else
#define VEC_INLINE_NEVER
#endif

#define _VEC_CHECK(cond, ...)                                                  \
    do {                                                                       \
        if (cond) {                                                            \
            break;                                                             \
        }                                                                      \
        fprintf(stderr, "VEC_CHECK failed at %s:%d\n", __FILE__, __LINE__);    \
        fprintf(stderr, __VA_ARGS__);                                          \
        fprintf(stderr, "\n");                                                 \
        fflush(stdout);                                                        \
        abort();                                                               \
    } while (0)

#ifdef NDEBUG
#define VMAP_CHECK(cond, ...) ((void)0)
#else
#define VEC_CHECK(cond, ...) _VEC_CHECK(cond, __VA_ARGS__)
#endif

#endif /* __VEC_BASE_H__ */
