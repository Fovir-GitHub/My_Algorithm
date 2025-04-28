/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        return (a == b ? -1 : max(a.length(), b.length()));
    }
};
// @lc code=end
