/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        return (s.find("LLL") == string::npos) &&
               (std::count(s.begin(), s.end(), 'A') < 2);
    }
};
// @lc code=end
