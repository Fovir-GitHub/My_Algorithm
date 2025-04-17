/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n) { return n > 0 && 1162261467 % n == 0; }
};
// @lc code=end

int main(void)
{
    Solution sol;

    sol.isPowerOfThree(1);

    return 0;
}