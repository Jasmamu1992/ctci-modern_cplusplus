#include "include/stacks_queues/stack.h"
#include <gtest/gtest.h>

TEST( STACK_TEST, THREE_ELEMENTS ) {
    algorithm::stack<int> input;
    ASSERT_TRUE( input.empty() );

    input.push( 5 );
    input.push( 6 );
    input.push( 7 );

    ASSERT_EQ( 3, input.size() );
    ASSERT_EQ( 7, input.top() );

    input.pop();

    ASSERT_EQ( 2, input.size() );
    ASSERT_EQ( 6, input.top() );

    input.pop();

    ASSERT_EQ( 1, input.size() );
    ASSERT_EQ( 5, input.top() );

    input.pop();

    ASSERT_EQ( 0, input.size() );
    ASSERT_TRUE( input.empty() );
}

TEST( STACK_TEST, OP_OVERLOAD ) {
    algorithm::stack<int> input1;
    algorithm::stack<int> input2;
    input1.push( 1 );
    input2.push( 1 );
    ASSERT_TRUE( input1 == input2 );
}