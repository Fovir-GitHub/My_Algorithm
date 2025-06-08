/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int> & timeSeries, int duration) {
        return inner_product(timeSeries.begin() + 1, timeSeries.end(),
                             timeSeries.begin(), duration, plus<>(),
                             [duration](int current, int previous) {
                                 return min(current - previous, duration);
                             });
    }
};
// @lc code=end
