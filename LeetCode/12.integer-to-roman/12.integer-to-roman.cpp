/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static string ROMAN_NUMBERS[4][10] = {
            "",     "I",    "II", "III", "IV",  "V",   "VI", "VII", "VIII",
            "IX",   "",     "X",  "XX",  "XXX", "XL",  "L",  "LX",  "LXX",
            "LXXX", "XC",   "",   "C",   "CC",  "CCC", "CD", "D",   "DC",
            "DCC",  "DCCC", "CM", "",    "M",   "MM",  "MMM"};

        string result("");
        int counter = 0;

        while (num) {
            result = ROMAN_NUMBERS[counter][num % 10] + result;
            counter++;
            num /= 10;
        }

        return result;
    }
};
// @lc code=end

int main(void) {
    int input = 0;
    Solution sol;

    while (cin >> input)
        cout << sol.intToRoman(input) << endl;

    return 0;
}