#pragma once
#include <limits>
#include <unordered_set>
#include "../trees_graphs/graph_grid.h"

namespace algorithm {
using Location   = typename graph_grid::cell_t;
using point      = Location;
using graph_type = typename graph_grid::graph_grid;
struct pair_hash {
    inline std::size_t operator()( const std::pair<size_t, size_t>& v ) const {
        return v.first * 31 + v.second;
    }
};
using hashSet_points = typename std::unordered_set<point, pair_hash>;

bool getPath( graph_type& grid, size_t row, size_t col, point& start, std::vector<point>& path,
              hashSet_points& failedPoints ) {
    if ( row < 1 || col < 1 || grid.cost( row, col ) == std::numeric_limits<int>::max() ) {
        return false;
    }
    point p = std::make_pair( row, col );
    if ( failedPoints.find( p ) != failedPoints.end() ) return false;
    bool isAtOrigin = ( row == start.first ) && ( col == start.second );
    if ( isAtOrigin || getPath( grid, row - 1, col, start, path, failedPoints ) ||
         getPath( grid, row, col - 1, start, path, failedPoints ) ) {
        path.push_back( p );
        return true;
    }
    failedPoints.insert( p );
    return false;
}

std::vector<point> find_path( graph_type grid, point start, point goal ) {
    std::vector<point> path;
    hashSet_points failedPoints;
    if ( grid.size().first == 0 ) return path;
    if ( getPath( grid, goal.first, goal.second, start, path, failedPoints ) ) {
        return path;
    } else
        return std::vector<point>{};
}
} // namespace algorithm