#include <iostream>
#include <string>
#include <map>
using namespace std;

int myAtoi(string s) {
    // Handle edge cases
    if (s.length() == 0 || s.find_first_of("0123456789") == string::npos) {
        return 0;
    }

    map<char, int>nums = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, 
                          {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    
    // Discard leading whitespace
    s = s.substr(s.find_first_not_of(" "));
    
    // If after the whitespace, there is a non-digit and non "+" or "-" character
    // We immediately return 0 
    if (s.find_first_of("0123456789+-") != 0) {
        return 0;
    }

    // Check the sign of the number and discard the "+" or "-" character
    bool isNegative;
    if (s[0] == '-') {
        isNegative = true;
        s = s.substr(1);
    }
    else if (s[0] == '+') {
        isNegative = false;
        s = s.substr(1);
    }
    else {
        isNegative = false;
    }

    // Discard leading 0s (only if there are non-zero digits, if not return 0)
    if (s.find_first_of("123456789") == string::npos) {
        return 0;
    }
    s = s.substr(s.find_first_not_of("0"));

    // Find where the number ends (the first non-digit character)
    // and discard everything after the number
    s = s.substr(0, s.find_first_not_of("0123456789"));

    // Clamp down numbers of magnitude greater than 2^31 - 1 = 2,147,483,647
    if (s.length() > 10) {
        if (isNegative) {
            return -1 * 2147483648;
        }
        return 2147483647;
    }
    if (s.length() == 10) {
        if (s[0] > '2' || (s[0] == '2' && myAtoi(s.substr(1)) > 147483647)) {
            if (isNegative) {
                return -1 * 2147483648;
            }
            return 2147483647;
        }
    }

    int result = 0;
    for (auto digit: s) {
        // Shift current digits to the left then add the new digit
        result *= 10;
        result += nums[digit];
    }

    if (isNegative) {
        return -1 * result;
    }
    return result;
}

int main() {
    cout << "Expected: 0, Actual: " << myAtoi("00000000") << endl;
    cout << "Expected: -42, Actual: " << myAtoi("   -42") << endl;
    cout << "Expected: 4193, Actual: " << myAtoi("4193 with words") << endl;
    cout << "Expected: 0, Actual: " << myAtoi("words and 987") << endl;
    cout << "Expected: -2147483648, Actual: " << myAtoi("-91283472332") << endl;
    cout << "Expected: 2147483647, Actual: " << myAtoi("10000294893") << endl;
    cout << "Expected: 9872, Actual: " << myAtoi("    +9872 and Gautam") << endl;
    return 0;
}