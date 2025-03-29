/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> & nums)
    {
        return (nums.size() * (nums.size() + 1)) / 2 -
               accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end

int main(void)
{
    vector<int> vec = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution    sol;

    cout << sol.missingNumber(vec) << endl;

    return 0;
}