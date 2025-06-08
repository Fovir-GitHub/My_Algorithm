/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
            if (i + k <= s.size())
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.end());

        return s;
    }
};
// @lc code=end

int main(void) {
    string s("abcd");
    int k = 2;
    Solution sol;

    cout << sol.reverseStr(s, k) << '\n';

    return 0;
}