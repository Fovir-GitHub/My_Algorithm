/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int> & nums) {
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());

        return nums.size();
    }
};
// @lc code=end

int main(void) {
    Solution sol;
    vector<int> number = {1, 1, 2};

    cout << sol.removeDuplicates(number) << '\n';
    for (auto it : number)
        cout << it << ' ';

    return 0;
}