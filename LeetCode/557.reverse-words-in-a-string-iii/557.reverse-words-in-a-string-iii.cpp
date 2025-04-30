/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        string::iterator iter     = s.begin();
        string::iterator word_end = s.begin();
        while (iter != s.end() && word_end != s.end())
        {
            word_end = std::find_if(iter, s.end(),
                                    [](char & ch) { return ch == ' '; });
            reverse(iter, word_end);
            iter = word_end + 1;
        }

        return s;
    }
};
// @lc code=end

int main(void)
{
    string   s = "Let's take LeetCode contest";
    Solution sol;

    cout << sol.reverseWords(s) << '\n';

    return 0;
}