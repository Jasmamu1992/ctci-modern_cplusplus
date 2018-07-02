#pragma once
#include <stdlib.h>
#include <time.h>
#include <initializer_list>

namespace algorithm {
class TreeNode {
    int data_;
    TreeNode* left_;
    TreeNode* right_;
    int size_;

public:
    TreeNode() : data_( 0 ), size_( 0 ), left_( nullptr ), right_( nullptr ) {}
    TreeNode( int d ) : data_( d ), size_( 1 ), left_( nullptr ), right_( nullptr ) {}
    ~TreeNode() = default;
    int data() {
        return data_;
    }
    int size() {
        return size_;
    }

    void insertInOrder( int d ) {
        if ( d <= data_ ) {
            if ( !left_ )
                left_ = new TreeNode( d );
            else
                left_->insertInOrder( d );
        } else {
            if ( !right_ )
                right_ = new TreeNode( d );
            else
                right_->insertInOrder( d );
        }
        ++size_;
    }

    TreeNode* find( int d ) {
        if ( d == data_ )
            return this;
        else if ( d < data_ )
            return left_ != nullptr ? left_->find( d ) : nullptr;
        else
            return right_ != nullptr ? right_->find( d ) : nullptr;
        return nullptr;
    }

    TreeNode* getRandomNode() {
        int leftSize = left_ == nullptr ? 0 : left_->size();
        srand( time( NULL ) );
        int index = rand() % size_;
        if ( index < leftSize )
            return left_->getRandomNode();
        else if ( index == leftSize )
            return this;
        else
            return right_->getRandomNode();
    }

    TreeNode* searchFor( int key ) {
        if ( key == data_ )
            return this;
        else if ( key < data_ )
            return left_ ? left_->searchFor( key ) : nullptr;
        else
            return right_ ? right_->searchFor( key ) : nullptr;
    }
};

class bst {
    TreeNode* root;

public:
    bst() : root( nullptr ) {}
    bst( std::initializer_list<int> init ) : root( nullptr ) {
        for ( auto a : init ) {
            if ( !root )
                root = new TreeNode( a );
            else
                root->insertInOrder( a );
        }
    }
    ~bst() = default;
    TreeNode* getroot() {
        return root;
    }
    int size() {
        return root ? root->size() : 0;
    }
    TreeNode* getRandom() {
        if ( !root ) return nullptr;
        return root->getRandomNode();
    }

    TreeNode* find( int key ) {
        if ( !root ) return nullptr;
        return root->searchFor( key );
    }
};
} // namespace algorithm