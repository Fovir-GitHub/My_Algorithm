/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, int> pattern2s;
        map<string, int> s2pattern;
        istringstream iss(s);
        int i = 0;

        for (string word; iss >> word; i++) {
            if (i == pattern.size() || pattern2s[pattern[i]] != s2pattern[word])
                return false;

            pattern2s[pattern[i]] = s2pattern[word] = i + 1;
        }

        return i == pattern.size();
    }
};
// @lc code=end

int main(void) {
    string pattern, s;
    Solution sol;

    while (true) {
        cin >> pattern;
        cin.get();
        getline(cin, s);
        cout << sol.wordPattern(pattern, s) << '\n';
    }

    return 0;
}