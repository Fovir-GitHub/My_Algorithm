/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> & prices)
    {
        int buy     = prices[0];
        int profile = 0;

        for (size_t i = 1; i < prices.size(); i++)
        {
            buy     = std::min(buy, prices[i]);
            profile = std::max(profile, prices[i] - buy);
        }

        return profile;
    }
};
// @lc code=end

int main(void)
{
    std::vector<int> vec = {7, 6, 5, 4, 3, 2, 1};
    Solution         sol;

    std::cout << sol.maxProfit(vec) << '\n';
    return 0;
}