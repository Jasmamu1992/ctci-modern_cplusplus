#pragma once

namespace algorithm {
unsigned flips_required_shift( int first, int second ) {
    unsigned count = 0;
    for ( int c = first ^ second; c != 0; c >>= 1 ) {
        count += c & 1;
    }
    return count;
}

unsigned flips_required_trick( int first, int second ) {
    unsigned count = 0;
    for ( int c = first ^ second; c != 0; c &= c-1 ) {
        count ++;
    }
    return count;
}
} // namespace algorithm