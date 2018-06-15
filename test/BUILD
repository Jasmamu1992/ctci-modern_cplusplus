TEST_COPTS = [
    "-pedantic",
    "-pedantic-errors",
    "-std=c++17",
    "-Wall",
    "-Wextra",
    "-Wshadow",
    "-Wfloat-equal",
    "-fstrict-aliasing",
]

TEST_ARGS = ["--benchmark_min_time=0.01"]

PER_SRC_TEST_ARGS = ({
    "user_counters_tabular_test.cc": ["--benchmark_counters_tabular=true"],
})

cc_test(
name = "algorithms-test",
size = "small",
srcs = glob(["tests/arrays_strings/*.cpp",
             "tests/linked_lists/*.cpp",
             "tests/stacks_queues/*.cpp",
             "tests/bit_manipulation/insertion_bits_test.cpp",
             "tests/bit_manipulation/binary_string_test.cpp",
             "tests/bit_manipulation/flip_bit_win_test.cpp",
             "tests/bit_manipulation/next_number_test.cpp",
             "tests/bit_manipulation/conversion_flip_test.cpp",
             "tests/bit_manipulation/pairwise_swap_test.cpp",
             "tests/bit_manipulation/draw_line_test.cpp"]),
copts = TEST_COPTS,

deps = [
    "@benchmark//:benchmark",
    "@benchmark//:benchmark_internal_headers",        
    "@gtest//:gtest",
    "@gtest//:gtest_main",
    "//include/arrays_strings:arrays_strings",
    "//include/linked_lists:linked_lists",
    "//include/stacks_queues:stacks_queues",
    "//include/bit_manipulation:bit_manipulation"
],
) 