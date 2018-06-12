#pragma once
#include <functional>
#include <stack>

namespace algorithm{
template <typename T, typename compare=std::less<T>>
void sort_stack_variant(std::stack<T>& input, compare cmp = compare()){
    std::stack<T> sorted;
    while(!input.empty()){
        T temp = input.top();
        input.pop();
        while(!sorted.empty() && cmp(temp, sorted.top())){
            input.push(sorted.top());
            sorted.pop();
        }
        sorted.push(temp);
    }

    while(!sorted.empty()){
        input.push(sorted.top());
        sorted.pop();
    }
}

template <typename T, typename compare=std::less<T>>
std::stack<T> sort_stack(std::stack<T> input, compare cmp = compare()){
    std::stack<T> sorted;
    while(!input.empty()){
        T temp = input.top();
        input.pop();
        while(!sorted.empty() && cmp(sorted.top(), temp)){
            input.push(sorted.top());
            sorted.pop();
        }
        sorted.push(temp);
    }
    return sorted;
}
}
