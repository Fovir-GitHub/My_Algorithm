/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

 // @lc code=start
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> & strs)
    {
        string common_prefix("");
        int n = strs.size();
        int min_length = 2000;

        for (auto & it : strs)
            min_length = std::min(min_length, (int) it.length());

        if (min_length == 0)
            return common_prefix;

        for (int i = 0; i < min_length; i++)
        {
            bool same = true;
            for (int j = 1; j < n; j++)
                if (strs[j][i] != strs[j - 1][i])
                {
                    same = false;
                    break;
                }

            if (same)
                common_prefix += strs[0][i];
            else
                break;
        }
        return common_prefix;
    }
};
// @lc code=end

