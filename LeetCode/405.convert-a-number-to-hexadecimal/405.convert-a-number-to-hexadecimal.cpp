/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        // if (num == 0)
        //     return "0";

        // unsigned int n = static_cast<unsigned int>(num);
        // string       result;

        // while (n)
        // {
        //     int remain = n % 16;
        //     if (remain >= 10)
        //         result.insert(result.begin(), remain % 10 + 'a');
        //     else
        //         result = to_string(remain) + result;

        //     n /= 16;
        // }

        // return result;

        unsigned int        n = num;
        string              result;
        const static string hex_digits = "0123456789abcdef";

        do
        {
            result += hex_digits[n % 16];
            n /= 16;
        } while (n);

        return string(result.rbegin(), result.rend());
    }
};
// @lc code=end

int main(void)
{
    int      n;
    Solution sol;

    while (cin >> n) cout << sol.toHex(n) << '\n';

    return 0;
}