#include <cstdlib>
#include <vector>
#include <string_view>
#include <string>

class Solution {
private:
    int encoding(string_view s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        } 
        int num = stoi(static_cast<string>(s));
        return (num > 0 && num < 27) ? 1 : 0;
    }
public:
    int numDecodings(string s) {
        /* The approach:
         Base cases:
         Str of len 1 -> 1 (if we can encode it as a digit)
         Str of len 2 -> 1 (if we can encode each char as a digit) + 1 (if str of len 2 can be encoded as a digit)
         '0' can't be encoded to anything!
         Similarly numbers greater than 26 can't as well
         Use that whittle down possibilities
         We then build a bottom up DP solution
        */
        string_view sv(s);
        if (s.size() == 1) {
            // Handle edge case
            return encoding(sv);
        }
        vector<int> memo(s.size(), 0);
        
        memo[0] = encoding(sv.substr(sv.size() - 1));
        memo[1] = encoding(sv.substr(sv.size() - 2, 1)) * memo[0] + encoding(sv.substr(sv.size() - 2));
        for (size_t i = 2; i < sv.size(); ++i) {
            memo[i] = encoding(sv.substr(sv.size() - i - 1, 1)) * memo[i - 1] + encoding(sv.substr(sv.size() - i - 1, 2)) * memo[i - 2];
        }
        return memo.back();
    }
};
