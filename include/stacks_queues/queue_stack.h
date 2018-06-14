#pragma once
#include <deque>
#include <cstdlib>
#include <stdexcept>

namespace algorithm{
    template<typename T, typename Container = std::deque<T>> class queue_stack{
    public: 
    //Consturctors
    queue_stack(){}
    //destructor
    ~queue_stack(){}
    
    void push(const T& value) {
        stackNew.push_front(value);
    }
    T pop() {
        if(stackOld.empty()){
            if(stackNew.empty()) throw std::runtime_error("queue is empty");
            while(!stackNew.empty()){
                stackOld.push_front(stackNew.front());
                stackNew.pop_front();
            }
        }
        T retValue = stackOld.front();
        stackOld.pop_front();
        return retValue;
    }
    size_t size(){
        return stackOld.size()+stackNew.size();
    }
    T& front(){
        if(stackOld.empty()){
            if(stackNew.empty()) throw std::runtime_error("queue is empty");
            while(!stackNew.empty()){
                stackOld.push_front(stackNew.front());
                stackNew.pop_front();
            }
        }
        return stackOld.front();
    }
    bool empty(){
        return (stackOld.empty() && stackNew.empty());
    }
    private:
    Container stackNew;
    Container stackOld;
    };
}