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
srcs = glob(["tests/arrays_strings/*.cpp"]),
copts = TEST_COPTS,

    deps = [
        "@benchmark//:benchmark",
        "@benchmark//:benchmark_internal_headers",        
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        "//include/arrays_strings:arrays_strings",
    ],
) 