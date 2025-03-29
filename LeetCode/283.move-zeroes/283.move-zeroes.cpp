/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> & nums)
    {
        stable_partition(nums.rbegin(), nums.rend(), logical_not<int>());
    }
};
// @lc code=end

int main(void)
{
    Solution    sol;
    vector<int> v = {0, 1, 0, 3, 12};

    sol.moveZeroes(v);

    for (auto it : v) cout << it << ' ';

    cout << endl;

    return 0;
}