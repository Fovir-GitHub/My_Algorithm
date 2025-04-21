/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        string vowels = "aeiou";
        int    left = 0, right = s.size() - 1;

        while (left < right)
        {
            while (vowels.find(tolower(s[left])) == string::npos &&
                   left < right)
                left++;

            while (vowels.find(tolower(s[right])) == string::npos &&
                   right > left)
                right--;

            std::swap(s[left], s[right]);
            left++, right--;
        }

        return s;
    }
};
// @lc code=end

int main(void)
{
    string   input(" ");
    Solution sol;

    while (cin >> input) cout << sol.reverseVowels(input) << '\n';

    return 0;
}
