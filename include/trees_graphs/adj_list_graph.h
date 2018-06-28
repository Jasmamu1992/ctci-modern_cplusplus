#pragma once

#include <stddef.h>
#include <forward_list>
#include <vector>

namespace algorithm {
template<bool adjacent = false> class adj_list_graph {
public:
    using value_type      = int;
    using node_type       = int;
    using size_type       = size_t;
    using list_type       = typename std::forward_list<value_type>;
    using const_reference = const std::forward_list<value_type>&;
    using graph_type      = typename std::vector<std::forward_list<value_type>>;
    using iterator        = graph_type::iterator;

    adj_list_graph( size_type size ) : vertices{size}, _num_vertices{size}, _num_edges{0} {}
    size_type num_vertices() {
        return _num_vertices;
    }
    size_type num_edges() {
        return _num_edges;
    }
    bool empty() {
        return _num_vertices == 0;
    }
    void add_edge( value_type v1, value_type v2 ) {
        add_edge_helper( v1, v2 );
        if ( !adjacent ) add_edge_helper( v2, v1 );
        ++_num_edges;
    }
    const_reference adjacent_vertices( size_type vertex ) const {
        return vertices.at( vertex );
    }
    iterator begin() {
        return vertices.begin();
    }
    iterator end() {
        return vertices.end();
    }

private:
    std::vector<std::forward_list<value_type>> vertices;
    size_type _num_vertices;
    size_type _num_edges;
    void add_edge_helper( value_type v1, value_type v2 ) {
        vertices.at( v1 ).push_front( v2 );
    }
};
} // namespace algorithm