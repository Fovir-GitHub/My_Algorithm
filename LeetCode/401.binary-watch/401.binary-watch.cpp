/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (bitset<4>(h).count() + bitset<6>(m).count() == turnedOn)
                    result.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") +
                                     to_string(m));

        return result;
    }
};
// @lc code=end

int main(void) {
    Solution sol;
    int n;

    while (cin >> n) {
        for (auto it : sol.readBinaryWatch(n))
            cout << it << '\n';
        cout << "Finished\n";
    }

    return 0;
}