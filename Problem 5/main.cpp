#include <vector>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    // Handle smaller cases
    if (s.length() == 1) {
        return s;
    }
    
    if (s.length() == 2) {
        if (s[0] != s[1]) {
            s.pop_back();
        }
        return s;
    }
    
    /*
    Approach: Build a 2D bool memo 
    where each column corresponds to the start index on the string 
    and each row corresponds to len - 1 of substr
    */
    vector<vector<bool>> memo(s.length(), vector<bool>(s.length(), false));
    
    size_t startIdx = 0, substrLen = 1;
    for (size_t i = 0; i < s.length(); ++i) {
        for (size_t j = 0; j + i < s.length(); ++j) {
            // All substrings of size 1 are palindromes by default
            if (i == 0) {
                memo[i][j] = true;
                continue;
            }
            
            if (i == 1) {
                memo[i][j] = (s[j] == s[i + j]);
                if (memo[i][j] && (i + 1) > substrLen) {
                    substrLen = (i + 1);
                    startIdx = j;
                }
                continue;
            }
            
            // A substring is a palindrome if the jth char equals the first char of the substring
            // and the middle of the substring is a palindrome
            memo[i][j] = (s[j] == s[i + j] && memo[i - 2][j + 1]);
            if (memo[i][j] && (i + 1) > substrLen) {
                substrLen = (i + 1);
                startIdx = j;
            }
        }
    }
    
    return s.substr(startIdx, substrLen);
}
