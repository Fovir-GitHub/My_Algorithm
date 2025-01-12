/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;

        int start = 1;
        int end = x;
        int middle = -1;

        while (start <= end)
        {
            middle = start + (end - start) / 2;

            long long square = static_cast<long long>(middle) * middle;
            if (square > x)
                end = middle - 1;
            else if (square == x)
                return middle;
            else
                start = middle + 1;
        }

        return static_cast<int>(round(end));
    }
};
// @lc code=end
