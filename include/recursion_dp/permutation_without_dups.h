#pragma once
#include <string>
#include <vector>

namespace algorithm {
std::vector<std::string> perms_no_dups_bootomsup( std::string str ) {
    std::vector<std::string> permutations;
    if ( str.length() == 0 ) {
        permutations.push_back( "" );
        return permutations;
    }
    for ( size_t i = 0; i < str.length(); ++i ) {
        std::string first              = str.substr( 0, i );
        std::string second             = str.substr( i + 1 );
        std::vector<std::string> words = perms_no_dups_bootomsup( first + second );
        for ( auto word : words ) {
            permutations.push_back( str.at( i ) + word );
        }
    }
    return permutations;
}

std::vector<std::string> perms_no_dups( std::string str ) {
    std::vector<std::string> permutations;
    if ( str.length() == 0 ) {
        permutations.push_back( "" );
        return permutations;
    }
    char first                     = str.at( 0 );
    std::string rem                = str.substr( 1 );
    std::vector<std::string> words = perms_no_dups( rem );
    for ( std::string word : words ) {
        for ( size_t i = 0; i <= word.length(); ++i ) {
            std::string part1 = word.substr( 0, i );
            std::string part2 = word.substr( i );
            permutations.push_back( part1 + first + part2 );
        }
    }
    return permutations;
}
} // namespace algorithm