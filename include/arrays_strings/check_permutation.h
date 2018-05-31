#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <unordered_map>

namespace algorithm {
constexpr size_t NUM_CHAR = 256;

/*Implementation using unordered_maps
 *complexity Time:O(N), Memory:O(N)
 *N:number of characters in the string
 */
bool check_permutation_map( const std::string& string1, const std::string& string2 ) {
    if ( string1.length() != string2.length() ) return false;
    std::unordered_map<char, size_t> charcounter;
    for ( auto s : string1 ) {
        if ( charcounter.find( s ) != charcounter.end() ) charcounter[s] = 0;
        charcounter[s]++;
    }
    for ( auto s : string2 ) {
        if ( !charcounter.count( s ) ) return false;
        if ( charcounter[s] == 0 ) return false;
        charcounter[s]--;
    }
    return true;
}

/*Implementation using arrays
 *complexity Time:O(N), Memory:O(N)
 *N:number of characters in the string
 */
bool check_permutation_arraycount( const std::string& string1, const std::string& string2 ) {
    if ( string1.length() != string2.length() ) return false;
    std::array<size_t, NUM_CHAR> charcounter{};
    for ( auto s : string1 ) {
        charcounter.at( s )++;
    }
    for ( auto s : string2 ) {
        if ( charcounter.at( s ) == 0 ) return false;
        charcounter.at( s )--;
    }
    return true;
}

/*Implementation using sort
 *complexity Time:O(NlogN), Memory:O(N)
 *N:number of characters in the string
 */
bool check_permutation_sort( std::string string1, std::string string2 ) {
    if ( string1.length() != string2.length() ) return false;
    std::sort( string1.begin(), string1.end() );
    std::sort( string2.begin(), string2.end() );
    return ( string1.compare( string2 ) == 0 );
}

} // namespace algorithm