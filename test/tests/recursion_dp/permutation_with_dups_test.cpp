#include "include/recursion_dp/permutation_with_dups.h"
#include <gtest/gtest.h>

#include <unordered_set>

TEST( PERMS_WITH_DUPS, EMPTY_INPUT ) {
    auto output = algorithm::perms_dups( "" );
    ASSERT_EQ( "", output.front() );
    ASSERT_EQ( 1, output.size() );
}

TEST( PERMS_WITH_DUPS, ONE_LETTERS ) {
    std::unordered_set<std::string> expected_output = {"a"};
    auto output                                     = algorithm::perms_dups( "a" );
    std::unordered_set<std::string> output_set;
    for ( const auto& word : output ) {
        output_set.insert( word );
    }
    ASSERT_EQ( expected_output, output_set );
}

TEST( PERMS_WITH_DUPS, TWO_SAME_LETTERS ) {
    std::unordered_set<std::string> expected_output = {"aa"};
    auto output                                     = algorithm::perms_dups( "aa" );
    std::unordered_set<std::string> output_set;
    for ( const auto& word : output ) {
        output_set.insert( word );
    }
    ASSERT_EQ( expected_output, output_set );
}

TEST( PERMS_WITH_DUPS, THREE_LETTER_TWO_SAME ) {
    std::unordered_set<std::string> expected_output = {"aab", "aba", "baa"};
    auto output                                     = algorithm::perms_dups( "aab" );
    std::unordered_set<std::string> output_set;
    for ( const auto& word : output ) {
        output_set.insert( word );
    }
    ASSERT_EQ( expected_output, output_set );
}

TEST( PERMS_WITH_DUPS, THREE_LETTERS ) {
    std::unordered_set<std::string> expected_output = {"abc", "acb", "bac", "bca", "cab", "cba"};
    auto output                                     = algorithm::perms_dups( "abc" );
    std::unordered_set<std::string> output_set;
    for ( const auto& word : output ) {
        output_set.insert( word );
    }
    ASSERT_EQ( expected_output, output_set );
}
