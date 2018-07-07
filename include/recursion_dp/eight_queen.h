#pragma once
#include <cmath>
#include <cstddef>
#include <vector>

namespace algorithm {

bool checkValid( const std::vector<size_t>& columns, size_t row, size_t col ) {
    for ( size_t row2 = 0; row2 < row; ++row2 ) {
        size_t col2 = columns[row2];
        if ( col2 == col ) return false;
        size_t col_dist = ( col2 > col ) ? col2 - col : col - col2;
        size_t row_dist = ( row2 > row ) ? row2 - row : row - row2;
        if ( col_dist == row_dist ) return false;
    }
    return true;
}
void place_queen_helper( size_t row, std::vector<size_t> columns,
                         std::vector<std::vector<size_t>>& result, const size_t& grid_size ) {
    if ( row == grid_size ) {
        result.push_back( columns );
        return;
    }
    for ( size_t col = 0; col < grid_size; ++col ) {
        if ( checkValid( columns, row, col ) ) {
            columns[row] = col;
            place_queen_helper( row + 1, columns, result, grid_size );
        }
    }
}
std::vector<std::vector<size_t>> place_queens( const size_t& grid_size ) {
    std::vector<std::vector<size_t>> result;
    std::vector<size_t> columns( grid_size, 0 );
    place_queen_helper( 0, columns, result, grid_size );
    return result;
}
} // namespace algorithm