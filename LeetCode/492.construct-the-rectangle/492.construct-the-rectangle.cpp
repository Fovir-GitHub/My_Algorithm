/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int length = INT_MAX, width = INT_MAX, minimal_difference = INT_MAX;

        for (int i = 1; i <= sqrt(area); i++)
        {
            if (area % i == 0)
            {
                int j = area / i;
                if (j - i < minimal_difference)
                {
                    width              = i;
                    length             = j;
                    minimal_difference = j - i;
                }
            }
        }

        return {length, width};
    }
};
// @lc code=end

int main(void)
{
    int      n;
    Solution sol;

    while (cin >> n)
    {
        for (auto it : sol.constructRectangle(n)) cout << it << ' ';
        cout << '\n';
    }

    return 0;
}