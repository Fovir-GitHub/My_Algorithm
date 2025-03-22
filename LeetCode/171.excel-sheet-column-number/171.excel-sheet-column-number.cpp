/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        long result = 0;
        long base   = 1;

        for (auto iter = columnTitle.rbegin(); iter != columnTitle.rend();
             iter++)
        {
            result += (*iter - 'A' + 1) * base;
            base *= 26;
        }

        return result;
    }
};
// @lc code=end

int main(void)
{
    Solution sol;
    string   title;

    while (cin >> title) std::cout << sol.titleToNumber(title) << '\n';

    return 0;
}