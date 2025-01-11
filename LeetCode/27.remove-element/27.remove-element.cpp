/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> & nums, int val)
    {
        auto last = remove(nums.begin(), nums.end(), val);
        nums.erase(last, nums.end());

        return nums.size();
    }
};
// @lc code=end

int main(void)
{
    Solution sol;
    vector<int> numbers = {0, 1, 2, 2, 3, 0, 4, 2};

    cout << sol.removeElement(numbers, 2) << '\n';
    for (auto it : numbers) cout << it << ' ';

    return 0;
}