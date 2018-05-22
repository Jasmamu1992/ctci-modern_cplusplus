#include <string>

namespace algorithm{
    /*Implementation using independent writer and reader indices
    *complexity Time:O(N), Memory:O(1)
    *N:number of characters in the string
    */
    void urlify(std::string& str, size_t len){
        size_t writer = str.length() - 1;
        size_t reader = len - 1;
        while(reader > 0){
            if(str[reader]==' '){
                str[writer--] = '0';
                str[writer--] = '2';
                str[writer--] = '%';
            }
            else{
                str[writer--] = str[reader];
            }
            reader--;
        }
    }

    /*Implementation using independent writer and reader iterators
    *complexity Time:O(N), Memory:O(1)
    *N:number of characters in the string
    */
    void urlify_iterators(std::string& str, size_t len){
        auto writer = str.end() - 1;
        auto reader = str.begin() + len - 1;
        while(writer != str.begin()){
            if(*reader==' '){
                *writer-- = '0';
                *writer-- = '2';
                *writer-- = '%';
            }
            else{
                *writer-- = *reader;
            }
            reader--;
        }
    }


}

