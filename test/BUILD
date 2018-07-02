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
             "tests/trees_graphs/bst_test.cpp",
             "tests/trees_graphs/adj_list_graph_test.cpp",
             "tests/trees_graphs/route_nodes_test.cpp",
             "tests/trees_graphs/minimal_tree_test.cpp",
             "tests/trees_graphs/list_depths_test.cpp",
             "tests/trees_graphs/check_balanced_test.cpp",
             "tests/trees_graphs/validate_bst_test.cpp",
             "tests/trees_graphs/build_order_test.cpp",
             "tests/trees_graphs/common_ancestor_test.cpp",
             "tests/trees_graphs/check_subtree_test.cpp",
             "tests/trees_graphs/random_node_test.cpp",
             "tests/trees_graphs/path_sum_test.cpp"]),
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
     "//include/trees_graphs:trees_graphs"
],
) 