/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;

        while (left <= right) {
            long long middle = left + (right - left) / 2;

            if (middle * middle == num)
                return true;

            if (middle * middle > num)
                right = middle - 1;
            else
                left = middle + 1;
        }

        return false;
    }
};
// @lc code=end

int main(void) {
    int n;
    Solution sol;

    while (cin >> n)
        cout << sol.isPerfectSquare(n) << '\n';

    return 0;
}