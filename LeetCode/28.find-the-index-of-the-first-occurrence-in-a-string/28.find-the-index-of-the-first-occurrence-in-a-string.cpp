/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto result = haystack.find(needle);

        return result == string::npos ? -1 : result;
    }
};
// @lc code=end

int main(void) {
    Solution sol;
    string hay, needle;

    cin >> hay >> needle;
    cout << sol.strStr(hay, needle) << '\n';

    return 0;
}