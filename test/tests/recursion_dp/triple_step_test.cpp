#include "include/recursion_dp/triple_step.h"
#include <gtest/gtest.h>

TEST( TRIPLE_STEP, BASE_CASES ) {
    ASSERT_EQ( 1, algorithm::triple_step( 0 ) );
    ASSERT_EQ( 1, algorithm::triple_step( 1 ) );
    ASSERT_EQ( 2, algorithm::triple_step( 2 ) );
    ASSERT_EQ( 4, algorithm::triple_step( 3 ) );
    ASSERT_EQ( 7, algorithm::triple_step( 4 ) );
    ASSERT_EQ( 13, algorithm::triple_step( 5 ) );
}

TEST( TRIPLE_STEP, BASE_CASES_MEMORIZATION ) {
    ASSERT_EQ( 1, algorithm::step_memo( 0 ) );
    ASSERT_EQ( 1, algorithm::step_memo( 1 ) );
    ASSERT_EQ( 2, algorithm::step_memo( 2 ) );
    ASSERT_EQ( 4, algorithm::step_memo( 3 ) );
    ASSERT_EQ( 7, algorithm::step_memo( 4 ) );
    ASSERT_EQ( 13, algorithm::step_memo( 5 ) );
}
