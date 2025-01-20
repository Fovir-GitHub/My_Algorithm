/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result = {1};
        long long previous = 1;

        for (int i = 1; i <= rowIndex; i++)
        {
            long long next = previous * (rowIndex - i + 1) / i;
            result.push_back(next);
            previous = next;
        }

        return result;
    }
};
// @lc code=end

int main(void)
{
    int n;
    Solution sol;

    while (cin >> n)
    {
        vector<int> result = sol.getRow(n);
        for (auto i : result) cout << i << ' ';
        cout << endl;
    }

    return 0;
}