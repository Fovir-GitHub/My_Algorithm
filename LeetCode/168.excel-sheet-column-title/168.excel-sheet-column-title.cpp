/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

        while (columnNumber) {
            columnNumber--;
            result.insert(result.begin(), 'A' + columnNumber % 26);
            columnNumber /= 26;
        }

        return result;
    }
};
// @lc code=end

int main(void) {
    int n;
    Solution sol;

    while (cin >> n)
        std::cout << sol.convertToTitle(n) << '\n';

    return 0;
}