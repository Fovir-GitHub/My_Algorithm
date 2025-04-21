/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            int result = guess(middle);

            if (result == 0)
                return middle;

            if (result == -1)
                right = middle - 1;
            else
                left = middle + 1;
        }

        return 0;
    }
};
// @lc code=end
