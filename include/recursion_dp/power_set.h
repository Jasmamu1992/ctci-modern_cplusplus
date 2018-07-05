#pragma once
#include <iostream>
#include <vector>

namespace algorithm {
template<typename T> std::vector<T> converIntToSet( int x, std::vector<T> set ) {
    std::vector<T> subset;
    int index = 0;
    for ( int k = x; k > 0; k >>= 1 ) {
        if ( ( k & 1 ) == 1 ) subset.push_back( set.at( index ) );
        ++index;
    }
    return subset;
}

template<typename T> std::vector<std::vector<T>> power_set( std::vector<T>& input ) {
    std::vector<std::vector<T>> output;
    if ( input.empty() ) return output;
    std::vector<T> subset;
    size_t max = 1 << input.size();
    for ( int k = 0; k < max; ++k ) {
        subset = converIntToSet( k, input );
        output.push_back( subset );
    }
    return output;
} // namespace algorithm
} // namespace algorithm