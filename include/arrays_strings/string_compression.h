#pragma once
#include <string>

namespace algorithm{
    /*
    *Implementation 
    *complexity Time:O(N), Memory:O(N)
    *N:number of characters in the string
    */
    std::string compress(const std::string& instring){
        std::string str;
        auto pacer=instring.begin(), runner=instring.begin();
        unsigned int counter = 1;
        while (runner!=instring.end()){
            runner++;
            if(*pacer == *runner){
                counter++;
            }
            else{
                str+=*pacer;
                str+=std::to_string(counter);
                counter = 1;
                pacer = runner;
            }    
        }
        if(str.size()>=instring.size()) str = instring;
        return str;
    }
}