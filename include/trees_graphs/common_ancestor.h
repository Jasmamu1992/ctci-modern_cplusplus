#pragma once
#include <cmath>
#include "bst.h"

using node_type = typename algorithm::bst_node<int>*;
namespace algorithm {
int depth( node_type node ) {
    size_t dep = 0;
    while ( node ) {
        node = node->parent_;
        ++dep;
    }
    return dep;
}

node_type goUpBy( node_type node, int depth ) {
    while ( node && depth > 0 ) {
        node = node->parent_;
        --depth;
    }
    return node;
}

// solution if nodes have access to their parents
node_type first_common_ancestor( node_type first, node_type second ) {
    if ( first == nullptr || second == nullptr ) return nullptr;
    if ( first == second ) return first;
    int firstdepth        = depth( first );
    int seconddepth       = depth( second );
    int depthdiff         = firstdepth - seconddepth;
    node_type deepernode  = depthdiff > 0 ? first : second;
    node_type shallownode = depthdiff > 0 ? second : first;
    deepernode            = goUpBy( deepernode, std::abs( depthdiff ) );
    while ( deepernode && shallownode && deepernode != shallownode ) {
        deepernode  = deepernode->parent_;
        shallownode = shallownode->parent_;
    }
    return shallownode && deepernode ? shallownode : nullptr;
}
} // namespace algorithm