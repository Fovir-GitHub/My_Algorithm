/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1, 0);

        for (int i = 0; i <= n; i++) result[i] = bitset<32>(i).count();

        return result;
    }
};
// @lc code=end

int main(void)
{
    Solution sol;
    int      n;

    while (cin >> n)
    {
        for (const auto & it : sol.countBits(n)) cout << it << ' ';
        cout << '\n';
    }

    return 0;
}