/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> & g, vector<int> & s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int counter = 0;
        for (int i = 0; counter < g.size() && i < s.size(); i++)
            if (g[counter] <= s[i])
                counter++;

        return counter;
    }
};
// @lc code=end
