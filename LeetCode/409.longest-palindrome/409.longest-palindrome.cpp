/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        // unordered_set<char> record;
        // int                 length = 0;

        // for (const char & ch : s)
        // {
        //     if (record.count(ch))
        //     {
        //         record.erase(ch);
        //         length += 2;
        //     }
        //     else
        //         record.insert(ch);
        // }

        // return record.empty() ? length : length + 1;

        bitset<'z' - 'A' + 1> freq = 0;

        for (const char & ch : s)
            freq.flip(ch - 'A');
        int odd = freq.count();

        return s.size() - odd + (odd > 0);
    }
};
// @lc code=end

int main(void) {
    string s;
    Solution sol;

    while (cin >> s)
        cout << sol.longestPalindrome(s) << '\n';

    return 0;
}