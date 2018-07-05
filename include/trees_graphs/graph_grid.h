#pragma once
#include <array>
#include <cmath>
#include <cstddef>
#include <utility>
#include <vector>

namespace algorithm {
class graph_grid {
public:
    using cost_t     = int;
    using cell_t     = typename std::pair<size_t, size_t>;
    using graph_type = typename std::vector<std::vector<cost_t>>;
    graph_grid()     = default;
    explicit graph_grid( size_t rows, size_t cols, cost_t cost = cost_t{} )
        : rows_( rows ), cols_( cols ), grid_( rows + 2, std::vector<cost_t>( cols + 2, cost ) ) {}
    graph_grid( graph_grid& other ) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        grid_ = other.grid_;
    }
    graph_grid( graph_grid&& other ) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        grid_ = std::move( other.grid_ );
    }
    bool valid_loc( size_t row, size_t col ) const noexcept {
        if ( row < 1 || row > rows_ ) return false;
        if ( col < 1 || col > cols_ ) return false;
        return true;
    }
    bool valid_loc( cell_t loc ) const noexcept {
        return valid_loc( loc.first, loc.second );
    }
    auto left( cell_t cell ) const noexcept {
        return std::make_pair( cell.first, cell.second - 1 );
    }
    auto right( cell_t cell ) const noexcept {
        return std::make_pair( cell.first, cell.second + 1 );
    }
    auto up( cell_t cell ) const noexcept {
        return std::make_pair( cell.first - 1, cell.second );
    }
    auto down( cell_t cell ) const noexcept {
        return std::make_pair( cell.first + 1, cell.second );
    }
    std::vector<cell_t> neighbors( cell_t cell ) {
        if ( !valid_loc( cell ) ) std::__throw_invalid_argument( "invalid location" );
        std::vector<cell_t> neighbors;
        if ( valid_loc( left( cell ) ) ) neighbors.push_back( left( cell ) );
        if ( valid_loc( right( cell ) ) ) neighbors.push_back( right( cell ) );
        if ( valid_loc( up( cell ) ) ) neighbors.push_back( up( cell ) );
        if ( valid_loc( down( cell ) ) ) neighbors.push_back( down( cell ) );
        return neighbors;
    }
    std::vector<cell_t> neighbors( cell_t cell,
                                   const std::vector<std::pair<int, int>>& directions ) const
        noexcept {
        if ( !valid_loc( cell ) ) std::__throw_invalid_argument( "invalid location" );
        std::vector<std::pair<size_t, size_t>> neighbors;
        for ( const auto& dir : directions ) {
            auto next = cell_t{cell.first + dir.first, cell.second + dir.second};
            if ( valid_loc( next ) ) neighbors.push_back( next );
        }
        return neighbors;
    }
    cost_t cost( size_t row, size_t col ) const {
        if ( !valid_loc( row, col ) ) std::__throw_invalid_argument( "invalid location" );
        return grid_.at( row ).at( col );
    }
    cost_t cost( cell_t cell ) const {
        return cost( cell.first, cell.second );
    }
    void update_cost( size_t row, size_t col, cost_t cost ) {
        if ( !valid_loc( row, col ) ) std::__throw_invalid_argument( "invalid location" );
        grid_.at( row ).at( col ) = cost;
    }
    void update_cost( cell_t cell, cost_t cost ) {
        update_cost( cell.first, cell.second, cost );
    }
    cost_t manhattan_distance( cell_t from, cell_t to ) const {
        if ( !valid_loc( from ) || !valid_loc( to ) )
            std::__throw_invalid_argument( "invalid from or to location" );
        return std::abs( from.first - to.first ) + std::abs( from.second - to.second );
    }
    std::pair<size_t, size_t> size() {
        return std::make_pair( rows_, cols_ );
    }

private:
    size_t rows_;
    size_t cols_;
    std::vector<std::vector<cost_t>> grid_;
};
} // namespace algorithm