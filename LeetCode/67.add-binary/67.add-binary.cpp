/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.length() > b.length())
            swap(a, b);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        a.append(b.length() - a.length(), '0');

        int    n = a.length();
        string result("");
        int    next_plus = 0;

        for (int i = 0; i < n; i++)
        {
            int add_result = a[i] + b[i] - '0' - '0' + next_plus;
            next_plus      = add_result / 2;
            add_result %= 2;

            result += add_result + '0';
        }

        if (next_plus)
            result += '1';

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end

int main(void)
{
    Solution sol;
    string   a, b;

    while (cin >> a >> b) cout << sol.addBinary(a, b) << '\n';

    return 0;
}