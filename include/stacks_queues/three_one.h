#pragma once
#include<cstdlib>
#include<stdexcept>

namespace algorithm {
template<typename T> class MultiStack {
private:
    unsigned numberOfStacks;
    size_t stackCapacity;
    size_t* sizes;
    T* values;

public:
    MultiStack( unsigned numberStacks, size_t stack_size ) {
        numberOfStacks = numberStacks;
        stackCapacity        = stack_size;
        sizes = new size_t[numberOfStacks];
        for ( unsigned x = 0; x < numberOfStacks; ++x )
            sizes[x] = 0;
        values = new T[stack_size * numberStacks];
    }
    ~MultiStack() = default;
    void push( unsigned stackId, T value ) {
        if ( stackId < 0 || stackId > numberOfStacks )
            throw std::runtime_error( "stackId out of range" );
        if ( isFull( stackId ) ) throw std::runtime_error( "stack is full" );
        sizes[stackId]++;
        values[indexOfTop(stackId)] = value;
    }

    T top( unsigned stackId ) {
        if(isEmpty(stackId)) throw std::runtime_error( "the stack is empty" );
        return values[indexOfTop(stackId)];
    }

    void pop( unsigned stackId ) {
        if(isEmpty(stackId)) throw std::runtime_error( "the stack is empty" );
        values[indexOfTop(stackId)] = 0;
        sizes[stackId]--;
    }
    bool isFull( unsigned stackId ) {
        return sizes[stackId] >= stackCapacity;
    }
    bool isEmpty(unsigned stackId){
        return sizes[stackId]==0;
    }
    size_t size(unsigned stackId) {
        return sizes[stackId];
    }
    size_t indexOfTop( unsigned stackId) {
        return stackId * stackCapacity + sizes[stackId] - 1;
    }
};
} // namespace algorithms