#pragma once
#include <memory>
#include "forward_list.h"

namespace algorithm {

template<typename T> using nodePointer = std::shared_ptr<Forward_List_Node<T>>;

template<typename T> class Result {
public:
    nodePointer<T> tail;
    std::size_t size;
    Result( nodePointer<T> intail, std::size_t insize ) : tail( intail ), size( insize ) {}
    ~Result() {}
};

template<typename T> Result<T> getTailAndSize( nodePointer<T> head ) {
    if ( head == nullptr ) return Result<T>( nullptr, 0 );
    size_t size = 1;
    while ( head->next_ != nullptr ) {
        size++;
        head = head->next_;
    }
    return Result<T>( head, size );
}

template<typename T> nodePointer<T> getKthNode( nodePointer<T> head, size_t k ) {
    while ( k > 0 && head != nullptr ) {
        k--;
        head = head->next_;
    }
    return head;
}

template<typename T>
nodePointer<T> intersection_hash( nodePointer<T> head1, nodePointer<T> head2 ) {
    if ( head1 == nullptr || head2 == nullptr ) return nullptr;
    auto res1 = getTailAndSize( head1 );
    auto res2 = getTailAndSize( head2 );
    if ( res1.tail != res2.tail ) return nullptr;
    if ( res1.size > res2.size )
        head1 = getKthNode( head1, ( res1.size - res2.size ) );
    else if ( res2.size > res1.size )
        head2 = getKthNode( head2, ( res2.size - res1.size ) );
    while ( head1 != head2 ) {
        head1 = head1->next_;
        head2 = head2->next_;
    }
    return head1;
}
} // namespace algorithm