#pragma once
#include <vector>

namespace algorithm {
int make_change_recursive( const std::vector<int>& coins, int acc, int index ) {
    if ( acc == 0 ) return 1;
    if ( acc < 0 ) return 0;
    int ret = 0;
    for ( int a = index; a >= 0; --a ) {
        ret += make_change_recursive( coins, acc - coins.at( a ), a );
    }
    return ret;
}

int make_change_recursive( const std::vector<int>& coins, int acc ) {
    return make_change_recursive( coins, acc, coins.size() - 1 );
}

int make_change_dp( const std::vector<int>& coins, int acc, int index,
                    std::vector<std::vector<int>>& map ) {

    if ( acc == 0 ) return 1;
    if ( acc < 0 ) return 0;
    if ( map[index][acc] > 0 ) return map[index][acc];
    int ret = 0;
    for ( int a = index; a >= 0; --a ) {
        ret += make_change_recursive( coins, acc - coins.at( a ), a );
    }
    map[index][acc] = ret;
    return ret;
}
int make_change_dp( const std::vector<int>& coins, int acc ) {
    std::vector<std::vector<int>> map( coins.size() + 1, std::vector<int>( acc + 1, 0 ) );
    return make_change_dp( coins, acc, coins.size() - 1, map );
}
} // namespace algorithm