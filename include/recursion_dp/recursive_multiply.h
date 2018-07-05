#pragma once

namespace algorithm {
int recursive_multiply_helper( int smaller, int& bigger ) {
    if ( smaller == 0 ) return 0;
    if ( smaller == 1 ) return bigger;
    int s   = smaller >> 1;
    int val = recursive_multiply_helper( s, bigger );
    if ( smaller % 2 == 0 )
        return val + val;
    else
        return val + val + bigger;
}
int recursive_multiply( const int& val1, const int& val2 ) {
    int smaller = ( val1 > val2 ) ? val2 : val1;
    int bigger  = ( val1 > val2 ) ? val1 : val2;
    return recursive_multiply_helper( smaller, bigger );
}
} // namespace algorithm