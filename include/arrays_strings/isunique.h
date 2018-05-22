#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>

namespace algorithm{
    constexpr size_t NUM_CHAR = 256;

    /*
    *Implementation using bool array
    *complexity Time:O(N), Memory:O(N)
    *N:number of characters in the string
    */
    bool isUnique_hash( const std::string& input ) {
    if ( input.length() > NUM_CHAR ) return false;

    bool seen_chars[NUM_CHAR];
    for(unsigned int i=0; i<NUM_CHAR; ++i) seen_chars[i] = false;
    for ( auto letter : input ) {
        int let = (int) letter;
        if ( seen_chars[let] ) return false;
        seen_chars[let] = true;
    }
    return true;
    }

    /*
    *Implementation using vectors
    *complexity Time:O(N), Memory:O(N)
    *N:number of characters in the string
    */
    bool isUnique_vector( const std::string& input ) {
    if ( input.length() > NUM_CHAR ) return false;

    std::vector<bool> seen_chars( NUM_CHAR );
    for ( auto letter : input ) {
        if ( seen_chars.at( letter ) ) return false;
        seen_chars.at( letter ) = true;
    }
    return true;
    }

    /*
    *Implementation using unordered_map
    *complexity Time:O(N), Memory:O(N)
    *N:number of characters in the string
    */
    bool isUnique_map( const std::string& input ) {
    if ( input.length() > NUM_CHAR ) return false;

    std::map<char, bool> seen_chars;
    for ( auto letter : input ) {
        if ( seen_chars[letter] ) return false;
        seen_chars[letter] = true;
    }
    return true;
    }

    /*
    *Implementation using set
    *complexity Time:O(N), Memory:O(N)
    *N:number of characters in the string
    */
    bool isUnique_set( const std::string& input ) {
    if ( input.length() > NUM_CHAR ) return false;

    std::set<char> seen_chars;
    for ( auto letter : input ) {
        if ( seen_chars.find(letter)!=seen_chars.end() ) return false;
        seen_chars.insert(letter);
    }
    return true;
    }
}