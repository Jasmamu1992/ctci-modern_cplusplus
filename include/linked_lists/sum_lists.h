#pragma once
#include "forward_list.h"
#include <iostream>

namespace algorithm{
    /*
    *Implementation using iteration
    *complexity Time:O(N), Memory:O(N)
    *N:number of elements in list
    */
    template <typename T>
    std::shared_ptr<Forward_List_Node<T>> sum_lists(std::shared_ptr<Forward_List_Node<T>> list1, std::shared_ptr<Forward_List_Node<T>> list2){
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        std::shared_ptr<Forward_List_Node<T>> head = nullptr;
        auto head_runner = head;
        T carry = 0;
        while(list1!=nullptr || list2!=nullptr || carry!=0){
            T val1 = (list1==nullptr)?0:list1->value_;
            T val2 = (list2==nullptr)?0:list2->value_;
            auto value = val1 + val2 + carry;
            carry = value/10;
            value = value%10;
            auto newnode = std::make_shared<Forward_List_Node<T>>( value );
            if(head==nullptr) {
                head = newnode;
                head_runner = head;
            }
            else{
                head_runner->next_ = newnode;
                head_runner = head_runner->next_;
            }
            if (list1 != nullptr) list1=list1->next_;
            if (list2 != nullptr) list2=list2->next_;
        }
        return head;
    }

    /*
    *Implementation using recursion
    *complexity Time:O(N), Memory:O(N)
    *N:number of elements in list
    */
   template <typename T>
    std::shared_ptr<Forward_List_Node<T>> sum_lists_rec(std::shared_ptr<Forward_List_Node<T>> list1, std::shared_ptr<Forward_List_Node<T>> list2, T carry = 0){
        if(list1==nullptr && list2==nullptr && carry==0) return nullptr;
        T val1 = (list1==nullptr)?0:list1->value_;
        T val2 = (list2==nullptr)?0:list2->value_;
        auto value = val1 + val2 + carry;
        carry = value/10;
        value = value%10;
        auto head = std::make_shared<Forward_List_Node<T>>( value );
        list1 = (list1!=nullptr)?list1->next_:nullptr;
        list2 = (list2!=nullptr)?list2->next_:nullptr;
        auto retnode = sum_lists_rec(list1, list2, carry);
        head->next_ = retnode;
        return head;
    }
}