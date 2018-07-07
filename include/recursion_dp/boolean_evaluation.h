#pragma once
#include <string>
#include <unordered_map>

namespace algorithm {
bool stringToBool( std::string str ) {
    return str == "1" ? true : false;
}
std::string boolToString( bool bln ) {
    return bln ? "1" : "0";
}

int countEval( std::string input, bool result, std::unordered_map<std::string, int>& memo ) {
    if ( input.length() == 0 ) return 0;
    if ( input.length() == 1 ) return stringToBool( input ) == result ? 1 : 0;
    if ( memo.find( boolToString( result ) + input ) != memo.end() )
        return memo.at( boolToString( result ) + input );
    int ways = 0;
    for ( unsigned i = 1; i < input.length(); i += 2 ) {
        char c            = input.at( i );
        std::string left  = input.substr( 0, i );
        std::string right = input.substr( i + 1 );
        int leftTrue      = countEval( left, true, memo );
        int leftFalse     = countEval( left, false, memo );
        int rightTrue     = countEval( right, true, memo );
        int rightFalse    = countEval( right, false, memo );
        int total         = ( leftTrue + leftFalse ) * ( rightTrue + rightFalse );
        int totalTrue     = 0;
        if ( c == '^' )
            totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
        else if ( c == '&' )
            totalTrue = leftTrue * rightTrue;
        else if ( c == '|' ) {
            totalTrue = leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse;
        }
        int subWays = result ? totalTrue : total - totalTrue;
        ways += subWays;
    }
    memo[boolToString( result ) + input] = ways;
    return ways;
}
int boolean_evaluation( std::string input, bool result ) {
    std::unordered_map<std::string, int> memo;
    return countEval( input, result, memo );
}
} // namespace algorithm