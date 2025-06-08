/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int> & nums) {
        // sort(nums.begin(), nums.end());
        // for (size_t i = 0; i < nums.size() - 1; i += 2)
        //     if (nums[i] != nums[i + 1])
        //         return nums[i];

        // return nums.back();

        // int result = 0;
        // for (const auto & n : nums) result ^= n;

        // return result;

        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};
// @lc code=end

int main(void) {
    Solution sol;
    vector<int> vec = {2, 2, 1};
    std::cout << sol.singleNumber(vec) << '\n';

    return 0;
}