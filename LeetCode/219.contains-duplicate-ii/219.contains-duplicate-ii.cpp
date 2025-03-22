/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> & nums, int k)
    {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(nums[i]))
                if (i - hash[nums[i]] <= k)
                    return true;

            hash[nums[i]] = i;
        }

        return false;
    }
};
// @lc code=end

int main(void)
{
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int         k    = 2;
    Solution    sol;

    std::cout << sol.containsNearbyDuplicate(nums, k) << '\n';

    return 0;
}