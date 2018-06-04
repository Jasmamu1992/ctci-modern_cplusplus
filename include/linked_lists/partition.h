#pragma once
#include "forward_list.h"

namespace algorithm{
    template <typename T>
    std::shared_ptr<Forward_List_Node<T>> partition_stable(std::shared_ptr<Forward_List_Node<T>> head,
                                                           const T& key){
        
        if(head == nullptr) return head;
        auto runner = head;
        auto low = head;
        auto low_runner = head;
        auto high_runner = head;
        auto high = head;
        low = nullptr;
        high = nullptr;
        while(runner!=nullptr){
            if(runner->value_ < key){
                if(low == nullptr) {
                    low = runner;
                    low_runner = low;
                }
                else{
                    low_runner->next_ = runner;
                    low_runner = low_runner->next_;
                }
            }
            else{
                if(high == nullptr) {
                    high = runner;
                    high_runner = high;
                }
                else{
                    high_runner->next_ = runner;
                    high_runner = high_runner->next_;
                }
            }
            runner = runner->next_;
        }
        high_runner->next_ = runner;
        low_runner->next_ = high;
        return low;
    }
}