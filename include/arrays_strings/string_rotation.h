#pragma once
#include <string>

namespace algorithm{
    bool is_substr(const std::string& str, const std::string& substr){
        return std::string::npos!=str.find(substr);
    }
    bool is_rotation(const std::string& str, const std::string& substr){
        if((substr.size()!=str.size()) || str.size()==0) return false;
        std::string tempstr = str + str;
        return is_substr(tempstr,substr);
    }
}

