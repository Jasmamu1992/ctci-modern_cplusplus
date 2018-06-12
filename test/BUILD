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
             "tests/stacks_queues/stack_test.cpp",
             "tests/stacks_queues/three_one_test.cpp",
             "tests/stacks_queues/stack_min_test.cpp",
             "tests/stacks_queues/stack_plates_test.cpp",
             "tests/stacks_queues/queue_stack_test.cpp",
             "tests/stacks_queues/sort_stack_test.cpp",
             "tests/stacks_queues/animal_shelter.cpp"]),
copts = TEST_COPTS,

    deps = [
        "@benchmark//:benchmark",
        "@benchmark//:benchmark_internal_headers",        
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        "//include/arrays_strings:arrays_strings",
        "//include/linked_lists:linked_lists",
        "//include/stacks_queues:stacks_queues"
    ],
) 