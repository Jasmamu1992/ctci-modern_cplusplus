#pragma once
#include <deque>
#include <vector>
#include <cstdlib>
#include <stdexcept>

namespace algorithm{
template<typename T, typename container = std::deque<T>> class set_stacks{
    public:
    //constructors
    set_stacks(){}
    set_stacks(size_t capacity){
        _capacity = capacity;
    }
    //destructor
    ~set_stacks(){}

    //member funcs
    void push(const T& value){
        if(_vecOfStacks.empty()) {
            container cont;
            _vecOfStacks.push_back(cont);
        }
        if(_vecOfStacks.at(_vecOfStacks.size()-1).size()>=_capacity){
            container cont;
            _vecOfStacks.push_back(cont);
        } 
        _vecOfStacks.at(_vecOfStacks.size()-1).push_front(value);
    }
    T pop(){
        if(_vecOfStacks.at(_vecOfStacks.size()-1).size()==0) _vecOfStacks.pop_back();
        T value = _vecOfStacks.at(_vecOfStacks.size()-1).front();
        _vecOfStacks.at(_vecOfStacks.size()-1).pop_front();
        return value;
    }
    T& top(){
        if(_vecOfStacks.at(_vecOfStacks.size()-1).size()==0) _vecOfStacks.pop_back();
        return _vecOfStacks.at(_vecOfStacks.size()-1).front();
    }
    T& popAt(size_t stackInd){
        if(stackInd>_vecOfStacks.size()-1) throw std::runtime_error("Index out of range");
        T value = _vecOfStacks.at(stackInd).front();
        _vecOfStacks.at(stackInd).pop_front();
        return value;
    }
    bool empty() {
        if(_vecOfStacks.empty()) return true;
        if(_vecOfStacks.at(_vecOfStacks.size()-1).empty()) return true;
        return false;
    }
    size_t size() {
        return (_vecOfStacks.size()-1) * _capacity + 
                _vecOfStacks.at(_vecOfStacks.size()-1).size();
    }
    private:
    std::vector<container> _vecOfStacks;
    size_t _capacity;
};
}