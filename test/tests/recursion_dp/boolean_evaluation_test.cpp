#include "include/recursion_dp/boolean_evaluation.h"
#include <gtest/gtest.h>

TEST( BOOLEVAL, DEMO1 ) {
    std::string str = "1^0|0|1";
    ASSERT_EQ( 2, algorithm::boolean_evaluation( str, false ) );
}

TEST( BOOLEVAL, DEMO2 ) {
    std::string str = "0&0&0&1^1|0";
    ASSERT_EQ( 10, algorithm::boolean_evaluation( str, true ) );
}