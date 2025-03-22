/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> & nums)
    {
        if (nums.size() == 0)
            return vector<string>();

        vector<string> result;
        string         temp         = to_string(nums[0]);
        int            start        = nums[0];
        int            backup_start = start;

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != ++start)
            {
                if (start - backup_start > 1)
                    result.push_back(temp + "->" + to_string(start - 1));
                else
                    result.push_back(temp);

                start        = nums[i];
                backup_start = start;
                temp         = to_string(start);
            }

        if (backup_start != nums.back())
            result.push_back(temp + "->" + to_string(nums.back()));
        else
            result.push_back(temp);

        return result;
    }
};
// @lc code=end

int main(void)
{
    vector<int> number = {0, 2, 3, 4, 6, 8, 9};
    Solution    sol;

    auto result = sol.summaryRanges(number);
    for (auto & s : result) std::cout << s << '\n';

    return 0;
}
