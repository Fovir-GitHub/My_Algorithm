/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, j;
        for (i = s.size() - 1; i >= 0; i--)
            if (isalpha(s[i]))
                break;

        for (j = i - 1; j >= 0; j--)
            if (!isalpha(s[j]))
                break;

        cout << "i: " << i << '\n' << "j: " << j << '\n';
        return i - j;
    }
};
// @lc code=end

int main(void) {
    string s;
    Solution sol;

    while (getline(cin, s))
        cout << sol.lengthOfLastWord(s) << '\n';

    return 0;
}