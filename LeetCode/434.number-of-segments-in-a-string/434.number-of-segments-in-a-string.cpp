/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        istringstream iss(s);
        string temp;
        int count = 0;

        while (iss >> temp)
            count++;

        return count;
    }
};
// @lc code=end

int main(void) {
    Solution sol;
    string input;

    while (getline(cin, input))
        cout << sol.countSegments(input) << '\n';

    return 0;
}