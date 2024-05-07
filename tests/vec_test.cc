#include "../src/declare.h"
#include "../src/internal/test_helpers.h"
#include "gtest/gtest.h"

#define INT_VEC_SMALL_CAPACITY 10

VEC_DECLARE_WITH(int_vec, int, INT_VEC_SMALL_CAPACITY,
                 (VecType<int, INT_VEC_SMALL_CAPACITY>()));

VEC_HELPERS(int_vec, int);

TEST(Vector, Push) {
    int_vec vec = int_vec_new();

    for (int i = 0; i < INT_VEC_SMALL_CAPACITY; ++i) {
        push(vec, i);
    }

    EXPECT_EQ(int_vec_size(&vec), INT_VEC_SMALL_CAPACITY);

    int_vec_destory(&vec);
}

TEST(Vector, PushToAllocated) {
    int_vec vec = int_vec_new();

    for (int i = 0; i < INT_VEC_SMALL_CAPACITY + 1; ++i) {
        push(vec, i);
    }

    EXPECT_EQ(int_vec_size(&vec), INT_VEC_SMALL_CAPACITY + 1);

    int_vec_destory(&vec);
}

TEST(Vector, FindInSmall) {
    int_vec vec = int_vec_new();
    for (int i = 0; i < INT_VEC_SMALL_CAPACITY; ++i) {
        push(vec, i);
    }

    for (int i = 0; i < INT_VEC_SMALL_CAPACITY; ++i) {
        auto* f = find(vec, i);
        EXPECT_TRUE(f);
        EXPECT_EQ(*f, i);
    }

    int_vec_destory(&vec);
}

TEST(Vector, FindInAllocated) {
    int_vec vec = int_vec_new();
    for (int i = 0; i < INT_VEC_SMALL_CAPACITY + 1; ++i) {
        push(vec, i);
    }

    for (int i = 0; i < INT_VEC_SMALL_CAPACITY + 1; ++i) {
        auto* f = find(vec, i);
        EXPECT_TRUE(f);
        EXPECT_EQ(*f, i);
    }

    int_vec_destory(&vec);
}

TEST(Vector, PushOverCapacityAllocates) {
    int_vec vec = int_vec_new();

    for (int i = 0; i < INT_VEC_SMALL_CAPACITY; ++i) {
        push(vec, i);
    }

    auto* f0 = find(vec, 0);

    EXPECT_TRUE(f0);

    auto addr = [](int* v) { return (uintptr_t)v; };

    uintptr_t address0 = addr(f0);

    push(vec, 5);

    auto* f1 = find(vec, 0);

    uintptr_t address1 = addr(f1);

    EXPECT_NE(address0, address1);

    int_vec_destory(&vec);
}

TEST(Vector, At) {
    int_vec vec = int_vec_new();

    for (int i = 0; i < INT_VEC_SMALL_CAPACITY * 2; ++i) {
        push(vec, i);
        auto* f = at(vec, i);
        EXPECT_TRUE(f);
        EXPECT_EQ(*f, i);
    }

    int_vec_destory(&vec);
}

TEST(Vector, Clear) {
    int_vec vec = int_vec_new();

    push(vec, 0);
    EXPECT_EQ(int_vec_size(&vec), 1);

    int_vec_clear(&vec);

    EXPECT_EQ(int_vec_size(&vec), 0);

    int_vec_destory(&vec);
}
