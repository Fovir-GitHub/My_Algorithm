/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() <= 1)
            return true;

        if (islower(word[0]))
            return (find_if(word.begin(), word.end(), ::isupper) == word.end());
        else if (isupper(word[1]))
            return (find_if(word.begin(), word.end(), ::islower) == word.end());
        else
            return (find_if(word.begin() + 1, word.end(), ::isupper) ==
                    word.end());
    }
};
// @lc code=end

int main(void) {
    string s;
    Solution sol;

    while (cin >> s)
        cout << sol.detectCapitalUse(s) << '\n';

    return 0;
}