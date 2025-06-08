/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int> & nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1])
                return true;

        return false;
    }
};
// @lc code=end

int main(void) {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;

    cout << sol.containsDuplicate(nums) << '\n';

    return 0;
}
