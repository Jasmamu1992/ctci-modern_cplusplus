#pragma once
#include <string>
#include <vector>

namespace algorithm {
void generate_parens_helper( std::string str, int opencount, int closecount,
                             std::vector<std::string>& result ) {
    if ( opencount < 0 || opencount > closecount ) return;
    if ( closecount == 0 ) {
        result.push_back( str );
        return;
    }
    generate_parens_helper( str + "(", opencount - 1, closecount, result );
    generate_parens_helper( str + ")", opencount, closecount - 1, result );
}
std::vector<std::string> generate_parens( int n ) {
    std::vector<std::string> result;
    if ( n == 0 ) return result;
    generate_parens_helper( "(", n - 1, n, result );
    return result;
}
} // namespace algorithm