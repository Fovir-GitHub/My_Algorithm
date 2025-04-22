/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string temp = s + s;

        return temp.substr(1, temp.size() - 2).find(s) != string::npos;
    }
};
// @lc code=end
