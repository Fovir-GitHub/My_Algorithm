/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result;
        int    last = 0;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        if (num1.length() < num2.length())
            num1.append(string(num2.length() - num1.length(), '0'));
        else
            num2.append(string(num1.length() - num2.length(), '0'));

        for (int i = 0; i < num1.size(); i++)
        {
            int temp = num1[i] + num2[i] - '0' - '0' + last;
            result.append(to_string(temp % 10));
            last = temp / 10;
        }

        if (last)
            result.push_back('1');

        return {result.rbegin(), result.rend()};
    }
};
// @lc code=end

int main(void)
{
    Solution sol;
    string   a, b;

    while (cin >> a >> b) cout << sol.addStrings(a, b) << '\n';

    return 0;
}