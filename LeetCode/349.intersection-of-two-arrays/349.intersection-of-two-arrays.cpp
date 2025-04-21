/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> & nums1, vector<int> & nums2)
    {
        vector<int>        result;
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());

        for (const int & it : n2)
            if (n1.find(it) != n1.end())
                result.push_back(it);

        return result;
    }
};
// @lc code=end
