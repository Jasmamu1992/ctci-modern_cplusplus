#pragma once

namespace algorithm {
unsigned int next_number( unsigned int input ) {
    unsigned int c  = input;
    unsigned int c0 = 0;
    unsigned int c1 = 0;
    while ( ( ( c & 1 ) == 0 ) && ( c != 0 ) ) {
        c0++;
        c >>= 1;
    }
    while ( ( c & 1 ) == 1 ) {
        c1++;
        c >>= 1;
    }
    if ( ( c0 + c1 == sizeof( input ) * 8 ) || ( ( c0 + c1 ) == 0 ) ) return 0;
    unsigned int p = c0 + c1;
    input |= ( 1 << p );
    input &= ~( ( 1 << p ) - 1 );
    input |= ( 1 << ( c1 - 1 ) ) - 1;
    return input;
}

unsigned int prev_number( unsigned int input ) {
    unsigned int c  = input;
    unsigned int c0 = 0;
    unsigned int c1 = 0;
    while ( ( c & 1 ) == 1 ) {
        c1++;
        c >>= 1;
    }
    if ( c == 0 ) return -1;
    while ( ( c & 1 ) == 0 && c != 0 ) {
        c0++;
        c >>= 1;
    }
    unsigned p = c0 + c1;
    input &= ( ( ~0 ) << ( p + 1 ) );
    input |= ( ( 1 << ( c1 + 1 ) ) - 1 ) << ( c0 - 1 );
    return input;
}

} // namespace algorithm