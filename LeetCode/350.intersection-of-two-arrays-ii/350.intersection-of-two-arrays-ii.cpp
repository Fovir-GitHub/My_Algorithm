/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int> & nums1, vector<int> & nums2) {
        // unordered_map<int, int> count_nums1, count_nums2;
        // vector<int>             result;

        // for (const auto & it : nums1) count_nums1[it]++;
        // for (const auto & it : nums2) count_nums2[it]++;

        // for (const auto & [key, value] : count_nums1)
        //     if (count_nums2.count(key))
        //         for (int i = 0; i < min(value, count_nums2[key]); i++)
        //             result.push_back(key);

        // return result;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(),
                                     nums2.end(), nums1.begin()),
                    nums1.end());

        return nums1;
    }
};
// @lc code=end

int main(void) {
    Solution sol;
    vector<int> first = {1, 2, 2, 1}, second = {2, 2};

    for (const auto & it : sol.intersect(first, second))
        cout << it << ' ';

    return 0;
}