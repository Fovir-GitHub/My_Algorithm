/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int hammingWeight(int n) { return bitset<32>(n).count(); }
};
// @lc code=end

int main(void)
{
    int      n;
    Solution sol;

    while (cin >> n) cout << sol.hammingWeight(n) << '\n';

    return 0;
}
