/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class NumArray
{
private:
    vector<int> numbers;

public:
    NumArray(vector<int> & nums)
    {
        numbers.resize(nums.size());
        partial_sum(nums.begin(), nums.end(), numbers.begin());
    }

    int sumRange(int left, int right)
    {
        return numbers[right] - (left < 1 ? 0 : numbers[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

int main(void)
{
    vector<int> input = {-2, 0, 3, -5, 2, -1};
    NumArray    na(input);
    int         left, right;

    while (cin >> left >> right) cout << na.sumRange(left, right) << '\n';

    return 0;
}