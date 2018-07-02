#pragma once

#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace algorithm {

void dfs_build( char project, std::vector<char>& ordered_projects,
                const std::unordered_multimap<char, char>& dependency_pairs,
                std::unordered_set<char>& built, std::unordered_set<char>& built_same_root ) {
    built.insert( project );
    built_same_root.insert( project );
    auto range_adj = dependency_pairs.equal_range( project );
    for ( auto start = range_adj.first; start != range_adj.second; ++start ) {
        auto proj = ( *start ).second;
        if ( built_same_root.find( proj ) != built_same_root.end() )
            std::__throw_invalid_argument( "erro:cyclic dependency" );
        if ( built.find( proj ) == built.end() )
            dfs_build( proj, ordered_projects, dependency_pairs, built, built_same_root );
    }
    ordered_projects.push_back( project );
}

std::vector<char> build_order( std::vector<char> projects,
                               const std::unordered_multimap<char, char>& dependency_pairs ) {

    std::vector<char> ordered_projects;
    std::unordered_set<char> built;
    for ( const auto& project : projects ) {
        std::unordered_set<char> built_same_root;
        if ( built.find( project ) == built.end() )
            dfs_build( project, ordered_projects, dependency_pairs, built, built_same_root );
    }
    return ordered_projects;
}

// Jeshwanth
std::vector<char> build_order_sol2( std::vector<char> projects,
                                    const std::unordered_multimap<char, char>& dependency_pairs ) {
    std::vector<char> ordered_projects;
    std::unordered_map<char, int> toBeProcessed;
    for ( const auto& project : projects ) {
        toBeProcessed.insert( {project, 0} );
        auto range_adj = dependency_pairs.equal_range( project );
        for ( auto start = range_adj.first; start != range_adj.second; ++start ) {
            ++toBeProcessed.at( project );
        }
    }
    int zero_elements;
    while ( !toBeProcessed.empty() ) {
        zero_elements = 0;
        for ( auto it = toBeProcessed.begin(); it != toBeProcessed.end(); ) {
            if ( it->second == 0 ) {
                zero_elements++;
                ordered_projects.push_back( it->first );
                for ( auto it2 = dependency_pairs.begin(); it2 != dependency_pairs.end(); ++it2 ) {
                    if ( it2->second == it->first ) --toBeProcessed.at( it2->first );
                }
                it = toBeProcessed.erase( it );
            } else
                ++it;
        }
        if ( zero_elements == 0 ) std::__throw_invalid_argument( "erro:cyclic dependency" );
    }
    return ordered_projects;
}

} // namespace algorithm
