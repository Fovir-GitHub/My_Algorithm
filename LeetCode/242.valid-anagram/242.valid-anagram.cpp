/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // if (s.length() != t.length())
        //     return false;

        // for (const auto & ch : s)
        // {
        //     size_t t_pos = t.find(ch);
        //     if (t_pos == string::npos)
        //         return false;
        //     else
        //         t.erase(t_pos, 1);
        // }

        // return t.empty();

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // return s == t;

        if (s.length() != t.length())
            return false;

        vector<int> record(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            record[s[i] - 'a']++;
            record[t[i] - 'a']--;
        }

        for (const auto & it : record)
            if (it)
                return false;

        return true;
    }
};
// @lc code=end

int main(void)
{
    string   s, t;
    Solution sol;

    while (cin >> s >> t) std::cout << sol.isAnagram(s, t) << '\n';

    return 0;
}