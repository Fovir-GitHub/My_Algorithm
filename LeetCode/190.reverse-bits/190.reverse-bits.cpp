/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        // string s = bitset<32>(n).to_string();
        // reverse(s.begin(), s.end());

        // return bitset<32>(s).to_ulong();

        uint32_t result = 0;

        for (int i = 0; i < 32; i++)
        {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }

        return result;
    }
};
// @lc code=end

int main(void)
{
    uint32_t n;
    Solution sol;

    while (cin >> n) cout << sol.reverseBits(n) << '\n';

    return 0;
}