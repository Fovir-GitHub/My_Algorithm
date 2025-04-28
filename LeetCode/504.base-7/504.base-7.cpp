/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";

        string result;
        bool   negative = (num < 0);
        num             = abs(num);

        while (num)
        {
            result.append(to_string(num % 7));
            num /= 7;
        }

        if (negative)
            result += '-';

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end

int main(void)
{
    int      n;
    Solution sol;

    while (cin >> n) cout << sol.convertToBase7(n) << '\n';

    return 0;
}