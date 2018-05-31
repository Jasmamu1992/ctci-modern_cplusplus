#pragma once
#include "forward_list.h"

namespace algorithm{
     /*
    *Implementation
    *complexity Time:O(1), Memory:O(1)
    *N:number of elements in list
    */
    template <typename T>
    void remove_node(std::shared_ptr<Forward_List_Node<T>> node){
        if(node==nullptr) return;
        else if(node->next_ == nullptr) {
            node = nullptr;
            return;
        }
        std::shared_ptr<Forward_List_Node<T>> next = node->next_;
        node->value_ = next->value_;
        node->next_ = next->next_;
    }
}