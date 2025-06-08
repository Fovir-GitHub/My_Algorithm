/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        // int result = num;
        // while ((result = addNumber(result)) >= 10);

        // return result;

        return (num % 9 == 0 && num != 0 ? 9 : num % 9);
    }

    // int addNumber(int n)
    // {
    //     int result = 0;
    //     while (n)
    //     {
    //         result += n % 10;
    //         n /= 10;
    //     }

    //     return result;
    // }
};
// @lc code=end

int main(void) {
    int n;
    Solution sol;

    while (std::cin >> n)
        std::cout << sol.addDigits(n) << '\n';

    return 0;
}