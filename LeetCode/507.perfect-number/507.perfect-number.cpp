/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
            return false;

        int sum = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0)
                sum = sum + i + (num / i);
            if (sum > num)
                return false;
        }

        return sum == num;
    }
};
// @lc code=end
