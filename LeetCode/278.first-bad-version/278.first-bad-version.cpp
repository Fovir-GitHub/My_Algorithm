/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            if (isBadVersion(middle))
                right = middle;
            else
                left = middle + 1;
        }

        return left;
    }
};
// @lc code=end
