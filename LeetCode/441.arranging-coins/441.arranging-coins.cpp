/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

#include <climits>
#include <cmath>
#include <iostream>

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        // int count = 0;

        // for (int i = 1; i <= n; i++)
        // {
        //     n -= i;
        //     count++;
        // }

        // return count;

        int left = 1, right = n;
        int result = 0;

        while (left <= right)
        {
            long long middle = left + (right - left) / 2;
            long long temp   = middle * (middle + 1) / 2;

            if (temp <= n)
            {
                result = middle;
                left   = middle + 1;
            }
            else
                right = middle - 1;
        }

        return result;
    }
};
// @lc code=end

int main(void)
{
    Solution sol;
    int      n;

    std::cout << int(std::pow(2, 31) - 1) << '\n';

    while (std::cin >> n) std::cout << sol.arrangeCoins(n) << '\n';

    return 0;
}