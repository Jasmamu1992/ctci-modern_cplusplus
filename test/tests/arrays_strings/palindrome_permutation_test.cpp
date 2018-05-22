#include "include/arrays_strings/palindrome_permutation.h"
#include <gtest/gtest.h>
#include <string>

using algorithm::is_palindrome_permutation;

TEST( PALINDROME_PERMUTATION, EMPTY_STRING ) {
    ASSERT_TRUE( is_palindrome_permutation( "" ) );
}

TEST( PALINDROME_PERMUTATION, ONE_CHAR ) {
    ASSERT_TRUE( is_palindrome_permutation( "a" ) );
}

TEST( PALINDROME_PERMUTATION, SIMPLE_ODD ) {
    ASSERT_TRUE( is_palindrome_permutation( "aba" ) );
}

TEST( PALINDROME_PERMUTATION, SIMPLE_EVEN ) {
    ASSERT_TRUE( is_palindrome_permutation( "abba" ) );
}

TEST( PALINDROME_PERMUTATION, NOT_IN_ORDER ) {
    ASSERT_TRUE( is_palindrome_permutation( "abbackcddffhhggk" ) );
}

TEST( PALINDROME_PERMUTATION, SIMPLE_ODD_FALSE ) {
    ASSERT_FALSE( is_palindrome_permutation( "ab" ) );
}

TEST( PALINDROME_PERMUTATION, SIMPLE_EVEN_FALSE ) {
    ASSERT_FALSE( is_palindrome_permutation( "abbacd" ) );
}

TEST( PALINDROME_PERMUTATION, NOT_IN_ORDER_FALSE ) {
    ASSERT_FALSE( is_palindrome_permutation( "abbckcdffhhggk" ) );
}

TEST( PALINDROME_PERMUTATION, UPPER_CASE ) {
    ASSERT_TRUE( is_palindrome_permutation( "Aba" ) );
}

TEST( PALINDROME_PERMUTATION, SPACE1 ) {
    ASSERT_TRUE( is_palindrome_permutation( "Tact Coa" ) );
}

TEST( PALINDROME_PERMUTATION, SPACE2 ) {
    ASSERT_TRUE( is_palindrome_permutation( "Ding Dong" ) );
}

TEST( PALINDROME_PERMUTATION, SPACE3 ) {
    ASSERT_TRUE( is_palindrome_permutation( "Belly be" ) );
}
