#pragma once
#include <iostream>

namespace algorithm {
unsigned long long triple_step( int nsteps ) {
    if ( nsteps == 0 ) return 1;
    if ( nsteps < 0 ) return 0;
    return triple_step( nsteps - 1 ) + triple_step( nsteps - 2 ) + triple_step( nsteps - 3 );
}

// solution with memorization
long long step_memo( int nsteps, long long* memo ) {
    if ( nsteps == 0 ) return 1;
    if ( nsteps < 0 ) return 0;
    if ( memo[nsteps] == 0 ) {
        memo[nsteps] = step_memo( nsteps - 1, memo ) + step_memo( nsteps - 2, memo ) +
                       step_memo( nsteps - 3, memo );
    }
    return memo[nsteps];
}

long long step_memo( int nsteps ) {
    long long* memo = new long long[nsteps + 1];
    for ( int i = 0; i < nsteps + 1; ++i )
        memo[i] = 0;
    return step_memo( nsteps, memo );
}
} // namespace algorithm