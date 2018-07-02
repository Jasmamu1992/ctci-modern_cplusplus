#pragma once
#include <deque>
#include <vector>
#include "adj_list_graph.h"

using node      = typename algorithm::adj_list_graph<true>::node_type;
using list_type = typename algorithm::adj_list_graph<true>::const_reference;

namespace algorithm {
bool route_between_nodes( adj_list_graph<true> graph, node start, node end ) {
    auto graph_size = graph.num_vertices();
    std::vector<bool> visited( graph_size );
    std::deque<node> queue;
    queue.push_back( start );
    visited.at( start ) = true;
    while ( !queue.empty() ) {
        node n = queue.front();
        queue.pop_front();
        if ( n == end ) {
            return true;
        }
        list_type r = graph.adjacent_vertices( n );
        for ( auto x = r.begin(); x != r.end(); ++x ) {
            if ( visited.at( *x ) == false ) {
                visited.at( *x ) = true;
                queue.push_back( *x );
            }
        }
    }
    return false;
}
} // namespace algorithm