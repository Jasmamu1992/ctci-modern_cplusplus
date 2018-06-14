#pragma once
#include <cstdint>
#include <iostream>
#include <vector>

namespace algorithm {
int flip_bit_win( int input ) {
    if ( input == -1 ) return sizeof( int ) * 8;
    int currentlength  = 0;
    int previouslength = 0;
    int maxlength      = 1;
    while ( input != 0 ) {
        if ( ( input & 1 ) == 0 ) {
            previouslength = ( input & 2 ) == 0 ? 0 : currentlength;
            currentlength  = 0;
        } else if ( ( input & 1 ) == 1 )
            currentlength++;
        maxlength = std::max( previouslength + 1 + currentlength, maxlength );
        input     = static_cast<unsigned int>( input ) >> 1;
    }
    return maxlength;
}
} // namespace algorithm