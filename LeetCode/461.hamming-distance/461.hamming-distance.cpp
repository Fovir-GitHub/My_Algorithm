/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        // bitset<32> first(x), second(y);
        // int        distance = 0;

        // for (int i = 0; i < first.size(); i++)
        //     if (first[i] != second[i])
        //         distance++;

        // return distance;

        // return bitset<32>(x ^ y).count();

        return __builtin_popcount(x ^ y);
    }
};
// @lc code=end

int main(void) {
    int x, y;
    Solution sol;

    while (cin >> x >> y)
        cout << sol.hammingDistance(x, y) << '\n';

    return 0;
}