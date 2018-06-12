#pragma once
#include <deque>
#include <type_traits>

namespace algorithm {
template<typename T, typename Container = std::deque<T>> class stack {
public:
    using container_type  = Container;
    using value_type      = typename Container::value_type;
    using size_type       = typename Container::size_type;
    using difference_type = typename Container::difference_type;
    using reference       = typename Container::reference;
    using const_reference = typename Container::const_reference;
    // constructors
    stack() {}
    stack( const Container& other ) {
        container( other );
    }
    stack( Container&& other ) {
        container( std::move( other ) );
    }
    stack( const stack& other ) {
        container( other.container );
    }
    stack( stack&& other ) {
        container( std::move( other.contianer ) );
    }
    // destructor
    ~stack() = default;
    reference top() {
        return container.front();
    }
    const_reference top() const {
        return container.front();
    }
    void push( const reference other ) {
        container.push_front( other );
    }

    void push( value_type&& other ) {
        container.push_front( std::move( other ) );
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
    void swap( stack& other ) noexcept {
        using std::swap;
        swap( container, other.container );
    }
    Container getcontainer() const {
        return container;
    }

protected:
    Container container;
};

template<typename T, typename Container>
bool operator==( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.getcontainer() == rhs.getcontainer();
}

template<class T, class Container>
bool operator!=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.getcontainer() != rhs.getcontainer();
}

template<class T, class Container>
bool operator<( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.getcontainer() < rhs.getcontainer();
}

template<class T, class Container>
bool operator<=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.getcontainer() <= rhs.getcontainer();
}

template<class T, class Container>
bool operator>( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.getcontainer() > rhs.getcontainer();
}

template<class T, class Container>
bool operator>=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.getcontainer() >= rhs.getcontainer();
}

template<class T, class Container>
void swap( stack<T, Container>& lhs, stack<T, Container>& rhs ) noexcept {
    lhs.swap( rhs );
}
} // namespace algorithm