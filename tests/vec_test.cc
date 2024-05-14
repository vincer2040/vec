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

TEST(Vector, FirstLast) {
    int_vec vec = int_vec_new();

    int* first = int_vec_first(&vec);
    EXPECT_FALSE(first);
    int* last = int_vec_back(&vec);
    EXPECT_FALSE(last);

    push(vec, 0);
    push(vec, 1);

    EXPECT_EQ(int_vec_size(&vec), 2);

    first = int_vec_first(&vec);
    EXPECT_TRUE(first);
    EXPECT_EQ(*first, 0);

    last = int_vec_back(&vec);
    EXPECT_TRUE(last);
    EXPECT_EQ(*last, 1);

    int_vec_destory(&vec);
}

TEST(Vector, Data) {
    int_vec vec = int_vec_new();
    int* data = int_vec_data(&vec);
    EXPECT_FALSE(data);

    int to_push[] = {0, 1, 2, 3, 4, 5, 6};
    size_t len = sizeof to_push / sizeof to_push[0];
    for (size_t i = 0; i < len; ++i) {
        push(vec, to_push[i]);
    }

    data = int_vec_data(&vec);
    EXPECT_TRUE(data);

    for (size_t i = 0; i < len; ++i) {
        int datai = data[i];
        int exp = to_push[i];
        EXPECT_EQ(datai, exp);
    }

    int_vec_destory(&vec);
}

TEST(Vector, Reserve) {
    int_vec vec = int_vec_new();

    int_vec_reserve(&vec, 6);

    EXPECT_EQ(int_vec_capacity(&vec), 10);

    push(vec, 0);

    int_vec_reserve(&vec, 11);

    EXPECT_EQ(int_vec_capacity(&vec), 11);
    EXPECT_EQ(int_vec_size(&vec), 1);

    int* f = at(vec, 0);
    EXPECT_TRUE(f);
    EXPECT_EQ(*f, 0);

    int_vec_destory(&vec);
}

TEST(Vector, PopBack) {
    int_vec vec = int_vec_new();
    int to_push[] = {0, 1, 2, 3, 4};
    size_t len = sizeof to_push / sizeof to_push[0];
    for (size_t i = 0; i < len; ++i) {
        push(vec, to_push[i]);
    }
    while (len--) {
        int out = 0;
        int_vec_pop_back(&vec, &out);
        int expected = to_push[len];
        EXPECT_EQ(out, expected);
    }
    int_vec_destory(&vec);
}

TEST(Vector, Erase) {
    int_vec vec = int_vec_new();
    std::vector<int> to_push = {0, 1, 2, 3, 4, 5};

    for (auto it : to_push) {
        push(vec, it);
    }

    for (size_t i = 0; i < to_push.size(); ++i) {
        int_vec_erase(&vec, 0);
        std::vector<int> got = collect(vec);
        to_push.erase(to_push.begin());
        EXPECT_EQ(got, to_push);
    }
    int_vec_destory(&vec);
}

TEST(Vector, Iterator) {
    int_vec vec = int_vec_new();
    int to_push[] = {0, 1, 2, 3, 4, 5};
    for (auto it : to_push) {
        push(vec, it);
    }

    size_t len = sizeof to_push / sizeof to_push[0];

    int_vec_iter it = int_vec_iter_new(&vec);
    size_t i = 0;
    while (int_vec_iter_get(&it)) {
        int expected = to_push[i];
        int* got = int_vec_iter_get(&it);
        EXPECT_TRUE(got);
        EXPECT_EQ(*got, expected);
        int_vec_iter_next(&it);
        i++;
    }
    EXPECT_FALSE(int_vec_iter_next(&it));
    EXPECT_EQ(i, len);
}
