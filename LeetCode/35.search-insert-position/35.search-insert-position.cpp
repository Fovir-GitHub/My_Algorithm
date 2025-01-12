/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> & nums, int target)
    {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(vector<int> & nums, int left, int right, int & target)
    {
        if (left > right)
            return left;

        int middle = left + (right - left) / 2;

        if (nums[middle] == target)
            return middle;

        if (nums[middle] < target)
            return binarySearch(nums, middle + 1, right, target);
        else
            return binarySearch(nums, left, middle - 1, target);
    }
};
// @lc code=end

int main(void)
{
    Solution sol;
    vector<int> vec = {1, 3, 5, 6};
    int target = 0;

    while (cin >> target) cout << sol.searchInsert(vec, target) << '\n';

    return 0;
}