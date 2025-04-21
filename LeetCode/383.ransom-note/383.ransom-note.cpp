/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // unordered_map<char, int> rans, maga;

        // for (const char & it : ransomNote) rans[it]++;
        // for (const char & it : magazine) maga[it]++;

        // for (const auto [key, value] : rans)
        //     if (!maga.count(key) || maga[key] < value)
        //         return false;

        // return true;

        int freq[26] = {0};
        for (const char & ch : magazine) freq[ch - 'a']++;
        for (const char & ch : ransomNote)
            if (--freq[ch - 'a'] < 0)
                return false;

        return true;
    }
};
// @lc code=end
