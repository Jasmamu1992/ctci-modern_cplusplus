
#include <forward_list>
#include <stack>

namespace algorithm {
template<typename T> bool is_palindrome_reverse( const std::forward_list<T>& list ) {
    std::forward_list<T> reversed_list( list );
    reversed_list.reverse();
    return reversed_list == list;
}

template<typename T> bool is_palindrome_stack( const std::forward_list<T>& list ) {
    std::stack<T> palstack;
    auto head   = list.begin();
    auto runner = list.begin();
    while ( runner != list.end() && ++runner != list.end() ) {
        ++runner;
        palstack.push( *head );
        ++head;
    }
    auto length = std::distance( list.begin(), list.end() );
    if ( length % 2 == 1 ) ++head; // taking care of odd length

    while ( head != list.end() ) {
        if ( palstack.top() != *head ) return false;
        palstack.pop();
        ++head;
    }
    return true;
}

//     template <typename T>
//     class Result{
//         public:
//         typename std::forward_list<T>::iterator node;
//         bool result;
//     };

//     template <typename T>
//     bool is_palindrome_rec(const std::forward_list<T>& list){
//         size_t length = std::distance(list.begin(), list.end());
//         auto p = ispalindrome(list.begin(), length);
//         return p.result;
//     }

//     template <typename T>
//     Result<T> ispalindrome(std::forward_list<T>::iterator head, size_t length){
//         if(head == nullptr || length<=0) return Result<T>(head, true);
//         if(length==1) return Result<T>(head+1, true);
//         auto res = ispalindrome(++head, length-2);
//         if(!res.result) return res;
//         res.result = (*res.node == *head);
//         ++res.node;
//         return res;
//     }
} // namespace algorithm
