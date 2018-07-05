#pragma once
#include <cstddef>
#include <stack>

namespace algorithm {
class Tower {
public:
    Tower() = default;
    Tower( std::initializer_list<int> list ) : disks_( list ) {}
    ~Tower() = default;
    size_t size() const noexcept {
        return disks_.size();
    }
    bool empty() const noexcept {
        return !disks_.size();
    }
    void add( int d ) {
        if ( !disks_.empty() && disks_.top() < d ) std::__throw_invalid_argument( "cannot add" );
        disks_.push( d );
    }
    void moveTopTo( Tower& t ) {
        t.add( disks_.top() );
        disks_.pop();
    }
    void move_disks( int n, Tower& destination, Tower& buffer ) {
        if ( n <= 0 ) return;
        move_disks( n - 1, buffer, destination );
        moveTopTo( destination );
        buffer.move_disks( n - 1, destination, *this );
    }
    friend bool operator==( const Tower& first, const Tower& second );

private:
    std::stack<int> disks_;
};

bool operator==( const Tower& first, const Tower& second ) {
    return first.disks_ == second.disks_;
}
} // namespace algorithm