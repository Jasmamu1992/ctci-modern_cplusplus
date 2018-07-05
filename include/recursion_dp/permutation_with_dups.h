#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace algorithm {
void perms_dups_helper( std::unordered_map<char, size_t>& map, std::string prefix, size_t remaining,
                        std::vector<std::string>& result ) {
    if ( remaining == 0 ) {
        result.push_back( prefix );
        return;
    }
    for ( auto a : map ) {
        size_t count = a.second;
        if ( count > 0 ) {
            --map.at( a.first );
            perms_dups_helper( map, prefix + a.first, remaining - 1, result );
            ++map.at( a.first );
        }
    }
}
void charCounter( std::unordered_map<char, size_t>& map, std::string& str ) {
    for ( auto a : str ) {
        if ( map.find( a ) == map.end() ) map.insert( {a, 0} );
        ++map.at( a );
    }
}
std::vector<std::string> perms_dups( std::string str ) {
    std::unordered_map<char, size_t> map;
    std::vector<std::string> result;
    charCounter( map, str );
    perms_dups_helper( map, "", str.length(), result );
    return result;
}
} // namespace algorithm