#include <string>
#include <vector>
#include <iostream>

bool palindrome_permutation(const std::string& str){
    constexpr size_t NUM_CHAR = 256;
    std::vector<bool> counter(256);
    for(auto s:str){
        counter.at(s) = (counter.at(s) != true);
    }
    unsigned int numTrue = 0;
    for(unsigned int i=0;i<NUM_CHAR;++i){
        if(counter.at(i)==true) numTrue++;
    }
    std::cout<<numTrue<<std::endl;
    return((str.length()%2)==numTrue);
}

using namespace std;
int main(){
    cout<< palindrome_permutation("ab  ma") << endl;
    return 0;
}



