/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result;
        int count = 0;

        for (string::reverse_iterator iter = s.rbegin(); iter != s.rend();
             iter++) {
            if (*iter == '-')
                continue;

            if (count == k) {
                result += '-';
                count = 0;
            }

            result += toupper(*iter);
            count++;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end

int main(void) {
    string s;
    int k;
    Solution sol;

    while (cin >> s >> k)
        cout << sol.licenseKeyFormatting(s, k) << '\n';

    return 0;
}