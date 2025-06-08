/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<char, int> record;
        // int                      result = INT_MAX;

        // for (int i = 0; i < s.size(); i++)
        //     if (record.count(s[i]))
        //         record[s[i]] = -1;
        //     else
        //         record[s[i]] = i;

        // for (const auto & [key, value] : record)
        //     if (value != -1)
        //         result = min(result, value);

        // return result == INT_MAX ? -1 : result;

        vector<int> frequence(26, 0);

        for (const char & ch : s)
            frequence[ch - 'a']++;

        for (int i = 0; i < s.size(); i++)
            if (frequence[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};
// @lc code=end

int main(void) {
    string s;
    Solution sol;

    while (cin >> s)
        cout << sol.firstUniqChar(s) << '\n';

    return 0;
}