#pragma once
#include <cmath>
#include <iostream>
#include "bst.h"

using node_pointer = typename algorithm::bst<int>::node_raw_pointer;
namespace algorithm {
size_t subTreeHeight( node_pointer root, node_pointer end, bool& balanced ) {
    if ( root == nullptr || root == end ) return 0;
    if ( !balanced ) return 0;
    size_t leftHeight  = subTreeHeight( root->left_.get(), end, balanced );
    size_t rightHeight = subTreeHeight( root->right_.get(), end, balanced );
    balanced &= ( std::abs( leftHeight - rightHeight ) <= 1 );
    return leftHeight + rightHeight + 1;
}

bool is_balanced( bst<int> input ) {
    node_pointer root( input.root() );
    if ( root == nullptr ) return false;
    node_pointer end( input.end_pointer() );
    bool balanced = true;
    std::cout << subTreeHeight( root, end, balanced ) << std::endl;
    return balanced;
}
} // namespace algorithm