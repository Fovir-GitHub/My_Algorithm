/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> & digits)
    {
        int next_plus = 0;

        *(digits.rbegin()) += 1;
        next_plus = *(digits.rbegin()) / 10;
        *(digits.rbegin()) %= 10;

        for (int i = digits.size() - 2; i >= 0; i--)
        {
            if (next_plus == 0)
                break;

            digits[i] += next_plus;
            next_plus = digits[i] / 10;
            digits[i] %= 10;
        }

        if (next_plus == 1)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
// @lc code=end

int main(void)
{
    Solution    sol;
    vector<int> numbers = {9, 9};
    vector<int> result  = sol.plusOne(numbers);

    for (auto it : result) cout << it << ' ';

    return 0;
}