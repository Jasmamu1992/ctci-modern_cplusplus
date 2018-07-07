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
             "tests/bit_manipulation/*.cpp",
             "tests/trees_graphs/*.cpp",
             "tests/recursion_dp/triple_step_test.cpp",
             "tests/recursion_dp/robot_grid_test.cpp",
             "tests/recursion_dp/magic_index_test.cpp",
             "tests/recursion_dp/power_set_test.cpp",
             "tests/recursion_dp/recursive_multiply_test.cpp",
             "tests/recursion_dp/towers_hanoi_test.cpp",
             "tests/recursion_dp/permutation_without_dups_test.cpp",
             "tests/recursion_dp/permutation_with_dups_test.cpp",
             "tests/recursion_dp/parens_test.cpp",
             "tests/recursion_dp/paint_fill_test.cpp",
             "tests/recursion_dp/coins_test.cpp",
             "tests/recursion_dp/eight_queen_test.cpp",
             "tests/recursion_dp/stack_boxes_test.cpp",
             "tests/recursion_dp/boolean_evaluation_test.cpp"]),
copts = TEST_COPTS,

deps = [
    "@benchmark//:benchmark",
    "@benchmark//:benchmark_internal_headers",        
    "@gtest//:gtest",
    "@gtest//:gtest_main",
    "//include/arrays_strings:arrays_strings",
    "//include/linked_lists:linked_lists",
    "//include/stacks_queues:stacks_queues",
    "//include/bit_manipulation:bit_manipulation",
    "//include/trees_graphs:trees_graphs",
    "//include/recursion_dp:recursion_dp"
],
) 