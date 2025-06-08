/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n - 1)) && !(bitset<32>(n - 1).count() & 1);
    }
};
// @lc code=end

int main(void) {
    int n;
    Solution sol;

    for (int i = 1; i <= 100; i *= 4)
        cout << i << " = " << bitset<32>(i).to_string() << '\n';

    while (cin >> n)
        cout << sol.isPowerOfFour(n) << '\n';

    return 0;
}