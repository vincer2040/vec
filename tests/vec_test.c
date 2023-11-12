#include "../src/vec.h"
#include <check.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

START_TEST(test_push_pop) {
    vec* vec = vec_new(sizeof(int));
    int a0 = 0, a1 = 1, a2 = 2, a3 = 3, a4 = 4, a5 = 5;
    int out;
    vec_push(&vec, &a0);
    vec_push(&vec, &a1);
    vec_push(&vec, &a2);
    vec_push(&vec, &a3);
    vec_push(&vec, &a4);
    vec_push(&vec, &a5);

    vec_pop(vec, &out);
    ck_assert_int_eq(out, 5);
    vec_pop(vec, &out);
    ck_assert_int_eq(out, 4);
    vec_pop(vec, &out);
    ck_assert_int_eq(out, 3);
    vec_pop(vec, &out);
    ck_assert_int_eq(out, 2);
    vec_pop(vec, &out);
    ck_assert_int_eq(out, 1);
    vec_pop(vec, &out);
    ck_assert_int_eq(out, 0);
    ck_assert_int_eq(vec_pop(vec, &out), -1);

    vec_free(vec, NULL);
}
END_TEST

Suite* ht_suite() {
    Suite* s;
    TCase* tc_core;
    s = suite_create("vec_test");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_push_pop);
    suite_add_tcase(s, tc_core);
    return s;
}

int main() {
    int number_failed;
    Suite* s;
    SRunner* sr;
    s = ht_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
