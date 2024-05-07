include(../cmake/GoogleTest.cmake)

add_executable(
    vec_test
    vec_test.cc
)

target_link_libraries(
    vec_test
    GTest::gtest_main
    GTest::gmock_main
)

include(GoogleTest)

gtest_discover_tests(vec_test)
