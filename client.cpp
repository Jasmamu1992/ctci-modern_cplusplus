#include <iostream>
#include <string>

namespace algorithm{
    bool is_rotation(const std::string& str, const std::string& substr){
        std::size_t subSize = substr.size();
        std::size_t strSize = str.size();
        std::string tempstr;
        if(subSize>strSize) return false;
        for(std::size_t i=0; i<strSize; ++i){
            if(strSize-i < subSize){
                tempstr = str.substr(i) + str.substr(0, i);
            }
            else{
                tempstr = str.substr(i, i+subSize);
            }
            std::cout << tempstr << std::endl;
            if(substr.compare(tempstr)==0) return true;
        }
        return false;
    }
}

using algorithm::is_rotation;
using namespace std;
int main(){
    cout << is_rotation( "abc", "abc" ) << endl;
    return 0;
}



