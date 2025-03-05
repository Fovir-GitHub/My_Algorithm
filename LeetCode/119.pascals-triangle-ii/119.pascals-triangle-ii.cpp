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
        vector<int> vec(rowIndex + 1, 0);
        vec[0] = 1;

        for (int i = 1; i < rowIndex + 1; i++)
            for (int j = i; j > 0; j--) vec[j] += vec[j - 1];

        return vec;
    }
};
// @lc code=end

int main(void)
{
    int      n;
    Solution sol;

    while (cin >> n)
    {
        vector<int> result = sol.getRow(n);
        for (auto i : result) cout << i << ' ';
        cout << endl;
    }

    return 0;
}