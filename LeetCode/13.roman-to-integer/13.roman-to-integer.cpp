/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> roman_number = {
            {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
            {'X', 10},   {'V', 5},   {'I', 1},
        };

        int result = 0;

        for (int i = 0; i < s.length() - 1; i++)
            if (roman_number[s[i]] < roman_number[s[i + 1]])
                result -= roman_number[s[i]];
            else
                result += roman_number[s[i]];
        result += roman_number[s[s.length() - 1]];

        return result;
    }
};
// @lc code=end

int main(void) {
    Solution sol;
    string input;

    while (cin >> input)
        cout << sol.romanToInt(input) << '\n';
    return 0;
}