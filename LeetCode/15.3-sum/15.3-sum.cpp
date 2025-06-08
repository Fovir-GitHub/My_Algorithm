/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> & nums) {
        int n = nums.size();
        int sums[n][n][n];
        vector<vector<int>> result;
        unordered_map<vector<vector<int>>, bool> hash;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++) {
                    sums[i][j][k] = nums[i] + nums[j] + nums[k];
                    vector<vector<int>> temp = {nums[i], nums[j], nums[k]};
                    if (sums[i][j][k] == 0 && i != j && j != k && !hash[temp]) {
                        hash[temp] = true;
                        result.push_back(temp);
                    }
                }

        return result;
    }
};
// @lc code=end

int main(void) {
    Solution sol;
    vector<int> v = {1, 2, 3};
    sol.threeSum(v);
    return 0;
}