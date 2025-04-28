/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
private:
    int record[31] = {0, 1, 0};

public:
    int fib(int n)
    {
        if (n == 0)
            return 0;

        return record[n] = (record[n] ? record[n] : fib(n - 1) + fib(n - 2));
    }
};
// @lc code=end
