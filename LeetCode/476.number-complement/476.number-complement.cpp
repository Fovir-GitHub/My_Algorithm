/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

#include <bit>
#include <bitset>
#include <iostream>

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        return (num == 0
                    ? 0
                    : ((~num) &
                       ((1u << std::bit_width(static_cast<unsigned int>(num))) -
                        1)));
    }
};
// @lc code=end

int main(void) {
    int n;
    Solution sol;

    while (std::cin >> n)
        std::cout << sol.findComplement(n) << '\n';

    return 0;
}