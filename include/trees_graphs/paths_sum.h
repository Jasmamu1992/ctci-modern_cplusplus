#pragma once
#include <unordered_map>
#include "bst.h"

namespace algorithm {
int path_with_sum_node( bst_node<int>* root, bst_node<int>* end, int targetSum, int currentSum ) {
    if ( !root || root == end ) return 0;
    currentSum += root->value_;
    int paths_current = 0;
    if ( currentSum == targetSum ) ++paths_current;
    paths_current += path_with_sum_node( root->left_.get(), end, targetSum, currentSum );
    paths_current += path_with_sum_node( root->right_.get(), end, targetSum, currentSum );
    return paths_current;
}
int path_with_sum_helper( bst_node<int>* root, bst_node<int>* end, int targetSum ) {
    if ( !root || root == end ) return 0;
    int paths_current = path_with_sum_node( root, end, targetSum, 0 );
    int paths_left    = path_with_sum_helper( root->left_.get(), end, targetSum );
    int paths_right   = path_with_sum_helper( root->right_.get(), end, targetSum );
    return paths_current + paths_left + paths_right;
}
int path_with_sum_naive( bst<int>& tree, int targetSum ) {
    return path_with_sum_helper( tree.root(), tree.end_pointer(), targetSum );
}

void incrementHashTable( std::unordered_map<int, int>& pathCount, int key, int delta ) {
    auto paths = pathCount.find( key );
    if ( paths != pathCount.end() ) {
        if ( paths->second + delta == 0 )
            pathCount.erase( key );
        else
            paths->second += delta;
        return;
    }
    pathCount.insert( std::make_pair( key, delta ) );
}
int running_sum_helper( bst_node<int>* root, bst_node<int>* end, int targetSum, int runningSum,
                        std::unordered_map<int, int>& pathCount ) {
    if ( !root || root == end ) return 0;
    runningSum += root->value_;
    int paths     = 0;
    int sum       = runningSum - targetSum;
    auto allpaths = pathCount.find( sum );
    if ( allpaths != pathCount.end() ) paths = allpaths->second;
    if ( runningSum == targetSum ) ++paths;
    incrementHashTable( pathCount, runningSum, 1 );
    paths += running_sum_helper( root->left_.get(), end, targetSum, runningSum, pathCount );
    paths += running_sum_helper( root->right_.get(), end, targetSum, runningSum, pathCount );
    incrementHashTable( pathCount, runningSum, -1 );
    return paths;
}

int path_with_sum_running_sum( bst<int>& tree, int targetSum ) {
    int runningSum = 0;
    std::unordered_map<int, int> pathCount;
    return running_sum_helper( tree.root(), tree.end_pointer(), targetSum, runningSum, pathCount );
}
} // namespace algorithm