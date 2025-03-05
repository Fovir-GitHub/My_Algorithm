/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 3)
            return n;

        vector<int> methods = {0, 1, 2, 0};
        methods.resize(46);

        for (int i = 3; i <= n; i++)
            methods[i] = methods[i - 1] + methods[i - 2];

        return methods[n];
    }
};
// @lc code=end

int main(void)
{
    Solution sol;
    int      n;

    while (cin >> n) cout << sol.climbStairs(n) << '\n';

    return 0;
}