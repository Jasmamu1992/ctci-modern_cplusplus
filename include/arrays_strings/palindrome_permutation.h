#pragma once
#include <string>
#include <vector>

namespace algorithm{
    bool is_palindrome_permutation(const std::string& str){
        constexpr size_t NUM_CHAR = 256;
        std::vector<bool> counter(256);
        int diff = 'a'-'A';
        int space = ' ';
        for(auto s:str){
            if ((s>='a') & (s<='z')) s-=diff;
            counter.at(s) = (counter.at(s) != true);
        }
        unsigned int numTrue = 0;
        for(unsigned int i=0;i<NUM_CHAR;++i){
            if(counter.at(i)==true) numTrue++;
        }
        if(counter.at(space)) numTrue-=2;
        // std::cout<<numTrue<<std::endl;
        return((str.length()%2)==numTrue);
    }
}