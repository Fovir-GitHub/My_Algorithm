/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        result.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < i; j++)
                temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            temp.push_back(1);
            result.push_back(temp);
        }

        return result;
    }
};
// @lc code=end

int main(void) {
    int n = 5;
    Solution sol;

    vector<vector<int>> vec = sol.generate(n);

    for (auto & v : vec) {
        for (auto it : v)
            cout << it << ' ';
        cout << '\n';
    }

    return 0;
}