/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        // if (n == 1)
        //     return true;

        // for (int i = 2; i <= sqrt(n); i++)
        // {
        //     while (n != i)
        //     {
        //         if (n % i == 0)
        //         {
        //             if (i != 2 && i != 3 && i != 5)
        //                 return false;
        //         }
        //         else
        //             break;

        //         n /= i;
        //     }
        // }

        // return (n == 2 || n == 3 || n == 5);

        // while (n > 1)
        // {
        //     if (n % 2 == 0)
        //         n /= 2;
        //     else if (n % 3 == 0)
        //         n /= 3;
        //     else if (n % 5 == 0)
        //         n /= 5;
        //     else
        //         return false;
        // }

        // return n == 1;

        for (int i = 2; i < 6 && n; i++)
            while (n % i == 0)
                n /= i;

        return n == 1;
    }
};
// @lc code=end

int main(void) {
    int n;
    Solution sol;

    while (cin >> n)
        cout << sol.isUgly(n) << '\n';

    return 0;
}
