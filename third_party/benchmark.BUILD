licenses(["notice"])

cc_library(
    name = "benchmark",
    srcs = glob([
        "src/*.cc",
        "src/*.h",
    ]),
    hdrs = ["include/benchmark/benchmark.h"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "benchmark_internal_headers",
    hdrs = glob(["src/*.h"]), 
    visibility = ["//visibility:public"],
)
