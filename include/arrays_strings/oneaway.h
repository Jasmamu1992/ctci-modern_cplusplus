#pragma once

#include <vector>
#include <string>
#include <cmath>

namespace algorithm{
    /*
    *Implementation 
    *complexity Time:O(N), Memory:O(1)
    *N:number of characters in the string
    */
    constexpr size_t NUM_CHAR = 256;
    bool one_edit_away(const std::string& first, const std::string& second){
        if (abs(first.size()-second.size())>1) return false;
        unsigned int mmcounter=0;
        unsigned int i=0, j=0;
        bool firstGreater = (first.size()>second.size());
        bool secondGreater = (first.size()<second.size());
        while((i<first.size()) & (j<second.size())){
            if (first.at(i)!=second.at(j)){
                mmcounter++;
                if(mmcounter > 1) return false;
                if(firstGreater) j--;
                else if (secondGreater) i--;
            } 
            i++, j++;
        }
        return true;
    }
}