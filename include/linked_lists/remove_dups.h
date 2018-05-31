#pragma once
#include <set>
#include <map>
#include <iostream>

#include "forward_list.h"

using algorithm::Forward_List;

namespace algorithm{
    /*
    *Implementation using std::set
    *complexity Time:O(N), Memory:O(N)
    *N:number of elements in list
    */
    template <class T>
    void remove_duplicates_map(Forward_List<T>& list){
        std::set<T> unique;
        auto head = list.front();
        while(head!=nullptr && head->next_!=nullptr){
            unique.insert(head->value_);
            if(unique.find(head->next_->value_)!=unique.end()){
                head->next_ = head->next_->next_;
            }
            head = head->next_;
        }
    }

    /*
    *Implementation without using additional memory
    *complexity Time:O(N^2), Memory:O(1)
    *N:number of characters in the string
    */
    template <class T>
    void remove_duplicates_NoBuffer(Forward_List<T>& list){
        auto head = list.front();
        auto runner = head;
        while(head!=nullptr){
            runner = head;
            while(runner->next_!=nullptr){
                if(runner->next_->value_ == head->value_){
                    runner->next_ = runner->next_->next_;
                }
                else runner = runner->next_;
            }
            head = head->next_;
        }
    }
}