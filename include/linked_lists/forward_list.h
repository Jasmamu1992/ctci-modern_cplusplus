#pragma once

#include <memory>

namespace algorithm {

template<typename T> struct Forward_List_Node {
    T value_;
    std::shared_ptr<Forward_List_Node> next_;

    // constructor
    Forward_List_Node( T value ) : value_( value ), next_( nullptr ) {}
    // Destructor
    ~Forward_List_Node() = default;
};

template<typename T> class Forward_List {
private:
    std::shared_ptr<Forward_List_Node<T>> head_;
    size_t size_;

public:
    using node_pointer = typename std::shared_ptr<Forward_List_Node<T>>;
    Forward_List() : head_( nullptr ), size_( 0 ) {}
    node_pointer push_front( T value );
    size_t size() { return size_; }
    node_pointer front() { return head_; }
};

template<typename T> typename Forward_List<T>::node_pointer Forward_List<T>::push_front( T value ){
    auto node   = std::make_shared<Forward_List_Node<T>>( value );
    node->next_ = head_;
    head_       = node;
    ++size_;
    return head_;
}

} // namespace algorithm