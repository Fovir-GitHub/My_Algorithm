/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> & nums) {
        vector<int> result;

        for (int & it : nums)
            while (nums[it - 1] != it)
                swap(it, nums[it - 1]);

        for (int i = 1; i <= nums.size(); i++)
            if (i != nums[i - 1])
                result.push_back(i);

        return result;
    }
};
// @lc code=end

int main(void) {
    vector<int> input = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution sol;

    for (const int & it : sol.findDisappearedNumbers(input))
        cout << it << ' ';

    return 0;
}