#pragma once
#include <string>

namespace algorithm {
// Solution by left shifting bits(multiplying with 2)
std::string binary_string( double x ) {
    if ( x >= 1 || x <= 0 ) return "ERROR";
    std::string binary;
    while ( x > 0 ) {
        if ( binary.length() >= 32 ) return "ERROR";
        x = x * 2;
        if ( x >= 1 ) {
            binary.append( "1" );
            x = x - 1;
        } else {
            binary.append( "0" );
        }
    }
    return binary;
}

// Solution without left shifting the bits
std::string binary_string_NoShift( double x ) {
    if ( x >= 1 || x <= 0 ) return "ERROR";
    double com = 1;
    std::string binary;
    while ( x > 0 ) {
        if ( binary.length() >= 32 ) return "ERROR";
        com = com * 0.5;
        if ( x >= com ) {
            binary.append( "1" );
            x = x - com;
        } else {
            binary.append( "0" );
        }
    }
    return binary;
}
} // namespace algorithm