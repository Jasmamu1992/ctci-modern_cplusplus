#pragma once
#include <cstddef>
#include <vector>

namespace algorithm {
// If elements in input are descrete
int magic_index_helper( std::vector<int>& input, int start, int end ) {
    if ( start > end ) return -1;
    int mid = ( start + end ) / 2;
    if ( mid == input.at( mid ) ) return mid;
    if ( mid < input.at( mid ) ) return magic_index_helper( input, start, mid - 1 );
    if ( mid > input.at( mid ) ) return magic_index_helper( input, mid + 1, end );
}

// If elements in input are not descrete
int magic_index_indescrete( std::vector<int>& input, int start, int end ) {
    if ( start > end ) return -1;
    int mid = ( start + end ) / 2;
    if ( mid == input.at( mid ) ) return mid;
    int left = magic_index_indescrete( input, start, std::min( mid - 1, input.at( mid ) ) );
    if ( left != -1 ) return left;
    int right = magic_index_indescrete( input, std::max( mid + 1, input.at( mid ) ), end );
    return right;
}

int magic_index( std::vector<int> input ) {
    if ( !input.size() ) return -1;
    return magic_index_indescrete( input, 0, input.size() - 1 );
}

} // namespace algorithm