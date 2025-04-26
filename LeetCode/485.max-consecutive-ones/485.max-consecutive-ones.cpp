/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> & nums)
    {
        int max_ones = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            while (i < nums.size() && nums[i] == 1)
            {
                count++;
                i++;
            }

            max_ones = max(max_ones, count);
        }

        return max_ones;
    }
};
// @lc code=end
