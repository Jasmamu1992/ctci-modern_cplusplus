#pragma once
#include "forward_list.h"

namespace algorithm {
template<typename T> using nodePointer = std::shared_ptr<Forward_List_Node<T>>;

template<typename T> nodePointer<T> loopBeginning( nodePointer<T> head ) {
    auto slow = head;
    auto fast = head;
    while ( fast->next_ != nullptr && fast != nullptr ) {
        slow = slow->next_;
        fast = fast->next_;
        fast = fast->next_;
        if ( slow == fast ) break;
    }
    if ( fast == nullptr || fast->next_ == nullptr ) return nullptr;
    slow = head;
    while ( slow != fast ) {
        slow = slow->next_;
        fast = fast->next_;
    }
    return slow;
}
} // namespace algorithm