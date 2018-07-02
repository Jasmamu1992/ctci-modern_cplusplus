#pragma once
#include "bst.h"

namespace algorithm {
template<typename T> bool is_bst( bst_node<T>* root, T min, T max, bst_node<T>* end ) {
    if ( root == nullptr || root == end ) return true;
    if ( root->value_ > max || root->value_ < min ) return false;
    return ( is_bst( root->left_.get(), min, root->value_, end ) &&
             is_bst( root->right_.get(), root->value_, max, end ) );
}

template<typename T> bool is_bst( bst<T>& input, T min, T max ) {
    return is_bst( input.root(), min, max, input.end_pointer() );
}

template<typename T> bool is_bst_successor( bst<T>& input, T min ) {
    T prev = min;
    for ( const auto& a : input ) {
        if ( a < prev ) return false;
        prev = a;
    }

    return true;
}
} // namespace algorithm