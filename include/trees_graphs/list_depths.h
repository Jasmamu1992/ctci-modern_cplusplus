#pragma once
#include <stddef.h>
#include <deque>
#include <forward_list>
#include <vector>
#include "bst.h"

using veclist      = std::vector<std::forward_list<int>>;
using node_pointer = typename algorithm::bst<int>::node_raw_pointer;
namespace algorithm {
void list_depth( node_pointer node, size_t depth, veclist& output, node_pointer end ) {
    if ( node == nullptr || node == end ) return;
    if ( depth == output.size() ) output.push_back( std::forward_list<int>{} );
    output.at( depth ).push_front( node->value_ );
    list_depth( node->left_.get(), depth + 1, output, end );
    list_depth( node->right_.get(), depth + 1, output, end );
}

veclist list_depth( bst<int>& input ) {
    veclist output;
    list_depth( input.root(), 0, output, input.end_pointer() );
    return output;
}
} // namespace algorithm