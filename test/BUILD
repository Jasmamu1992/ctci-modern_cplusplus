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
             "tests/linked_lists/forward_list_test.cpp",
             "tests/linked_lists/remove_dups_test.cpp",
             "tests/linked_lists/kth_tolast_test.cpp",
             "tests/linked_lists/remove_node.cpp",
             "tests/linked_lists/partition.cpp",
             "tests/linked_lists/sum_lists_test.cpp",
             "tests/linked_lists/palindrom_list_test.cpp",
             "tests/linked_lists/intersection.cpp",
             "tests/linked_lists/loop_detection_test.cpp"]),
copts = TEST_COPTS,

    deps = [
        "@benchmark//:benchmark",
        "@benchmark//:benchmark_internal_headers",        
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        "//include/arrays_strings:arrays_strings",
        "//include/linked_lists:linked_lists",
    ],
) 