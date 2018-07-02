#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "bst.h"

using node_pointer = typename algorithm::bst_node<int>*;
using bst_type     = typename algorithm::bst<int>;
namespace algorithm {
void getString( node_pointer root, const node_pointer& end, std::stringstream& str ) {
    if ( !root || root == end ) {
        str << "X";
        return;
    }
    str << root->value_;
    getString( root->left_.get(), end, str );
    getString( root->right_.get(), end, str );
}

bool is_subtree( bst_type& tree, bst_type& sub_tree ) {
    std::stringstream treeStr;
    std::stringstream sub_treeeStr;
    getString( tree.root(), tree.end_pointer(), treeStr );
    getString( sub_tree.root(), sub_tree.end_pointer(), sub_treeeStr );
    return ( treeStr.str().find( sub_treeeStr.str() ) != std::string::npos );
}
} // namespace algorithm