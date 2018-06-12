#pragma once
#include <deque>

namespace algorithm {

template<typename T> class stackNode {
public:
    T _data;
    T _min;
    stackNode(T data, T min){
        _data = data;
        _min = min;
    }
    stackNode(T data){
        _data = data;
        _min = data;
    }
    stackNode(const stackNode& node){
        _data = node._data;
        _min = node._min;
    }
    ~stackNode(){}
};

template<typename T, typename Container = std::deque<stackNode<T>>> class stack_min {
public:
    using value_type     = T;
    using size_type      = typename Container::size_type;

    // constructors
    stack_min() {}

    // destructor
    ~stack_min() = default;
  
    void push( const T& other ) {
        stackNode<T> node(other);
        if(container.empty()){
            container.push_front(node);
            return;
        }
        stackNode<T> prevNode(container.front());
        if(node._min > prevNode._min) node._min = prevNode._min;
        container.push_front(node);
    }

    void pop() {
        container.pop_front();
    }

    size_type size() const {
        return container.size();
    }
    bool empty() const {
        return container.empty();
    }

    value_type min(){
        return container.front()._min;
    }

protected:
    Container container;
};
}
