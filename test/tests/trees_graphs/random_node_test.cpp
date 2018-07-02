#include "include/trees_graphs/random_node.h"
#include <gtest/gtest.h>
#include <iostream>

TEST( RANDOM_NODE, DEMO ) {
    algorithm::bst tree = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    ASSERT_TRUE( tree.find( tree.getRandom()->data() ) != nullptr );
}
TEST( RANDOM_NODE, DEMO2 ) {
    algorithm::bst tree = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    ASSERT_TRUE( tree.find( tree.getRandom()->data() ) != nullptr );
}
TEST( RANDOM_NODE, DEMO3 ) {
    algorithm::bst tree;
    ASSERT_TRUE( tree.getRandom() == nullptr );
}