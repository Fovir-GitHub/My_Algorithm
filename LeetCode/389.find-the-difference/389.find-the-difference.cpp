/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        // vector<int> s_record(26, 0), t_record(26, 0);

        // for (const char & ch : s) s_record[ch - 'a']++;
        // for (const char & ch : t) t_record[ch - 'a']++;

        // for (int i = 0; i < s_record.size(); i++)
        //     if (s_record[i] != t_record[i])
        //         return i + 'a';

        // return 0;

        int result = 0;

        for (int i = 0; i < s.size(); i++) result = result - s[i] + t[i];
        result += t[s.size()];

        return result;
    }
};
// @lc code=end
