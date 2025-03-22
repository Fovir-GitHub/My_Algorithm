/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // unordered_map<char, char> s_to_t, t_to_s;

        // for (size_t i = 0; i < s.length(); i++)
        // {
        //     if ((s_to_t[s[i]] && s_to_t[s[i]] != t[i]) ||
        //         (t_to_s[t[i]] && t_to_s[t[i]] != s[i]))
        //         return false;

        //     s_to_t[s[i]] = t[i];
        //     t_to_s[t[i]] = s[i];
        // }

        // return true;

        vector<int> s_index(128, 0), t_index(128, 0);
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s_index[t[i]] != t_index[s[i]])
                return false;
            s_index[t[i]] = i + 1;
            t_index[s[i]] = i + 1;
        }

        return true;
    }
};
// @lc code=end

int main(void)
{
    string   s, t;
    Solution sol;

    while (cin >> s >> t) std::cout << sol.isIsomorphic(s, t) << '\n';

    return 0;
}