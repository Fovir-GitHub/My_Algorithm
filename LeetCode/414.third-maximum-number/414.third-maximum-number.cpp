/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int> & nums) {
        // set<int> freq;

        // for (const int & n : nums) freq.insert(n);

        // if (freq.size() < 3)
        //     return *freq.rbegin();

        // set<int>::iterator iter = freq.end();
        // advance(iter, -3);

        // return *iter;
        long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;

        for (const int & iter : nums) {
            if (iter > max1) {
                max3 = max2;
                max2 = max1;
                max1 = iter;
            } else if (iter > max2 && iter < max1) {
                max3 = max2;
                max2 = iter;
            } else if (iter > max3 && iter < max2)
                max3 = iter;
        }

        return max3 == LLONG_MIN ? max1 : max3;
    }
};
// @lc code=end

int main(void) {
    vector<int> nums = {1, 2};
    Solution sol;

    cout << sol.thirdMax(nums) << '\n';

    return 0;
}