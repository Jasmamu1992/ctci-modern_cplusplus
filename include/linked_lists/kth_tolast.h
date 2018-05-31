#pragma once
#include "forward_list.h"
#include <iostream>
using algorithm::Forward_List;

namespace algorithm {
     /*
    *Implementation if length of the list is known
    *complexity Time:O(N), Memory:O(1)
    *N:number of elements in list
    */
    template<typename T>
    typename Forward_List<T>::node_pointer kth_tolast_knownSize(Forward_List<T>& list, size_t k ) {
        if ( k > list.size() ) return nullptr;
        size_t count = list.size() - k;
        size_t cc    = 0;
        auto head    = list.front();
        while ( head != nullptr && cc < count ) {
            head = head->next_;
            cc++;
        }
        return head;
    }

     /*
    *Implementation using iteration if the size of list is unknown
    *complexity Time:O(N), Memory:O(1)
    *N:number of elements in list
    */
    template<typename T>
    typename Forward_List<T>::node_pointer kth_tolast_iterator(Forward_List<T>& list, size_t k ) {
        auto head = list.front();
        auto runner = list.front();
        for (size_t i=0; i<k; ++i){
            if(runner==nullptr) return runner;
            runner = runner->next_;
        }
        while(runner!=nullptr){
            head = head->next_;
            runner = runner->next_;
        }
        return head;
    }

     /*
    *Implementation using recursion if the size of list is unknown
    *complexity Time:O(N), Memory:O(1)
    *N:number of elements in list
    */
    template<typename T>
    std::shared_ptr<Forward_List_Node<T>> kth_tolast_runner(Forward_List<T>& list, size_t k){
        return kth_tolast(list.front(), k);
    }
   
    template<typename T>
    std::shared_ptr<Forward_List_Node<T>> kth_tolast(std::shared_ptr<Forward_List_Node<T>> head, size_t k) {
        static size_t counter = 0;
        if (head == nullptr) {
            counter = 0;
            return nullptr;
        }
        std::shared_ptr<Forward_List_Node<T>> node = kth_tolast(head->next_, k);
        counter += 1;
        if(counter == k){
            return head;
        }
        return node;
    }
} // namespace algorithm