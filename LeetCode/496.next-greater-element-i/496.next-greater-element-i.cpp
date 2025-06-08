/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> & nums1, vector<int> & nums2) {
        unordered_map<int, int> next_greater_element;
        vector<int> result(nums1.size(), -1);
        stack<int> st;

        for (const int & number : nums2) {
            while (!st.empty() && st.top() < number) {
                next_greater_element[st.top()] = number;
                st.pop();
            }

            st.push(number);
        }

        for (int i = 0; i < nums1.size(); i++)
            if (next_greater_element.count(nums1[i]))
                result[i] = next_greater_element.at(nums1[i]);

        return result;
    }
};
// @lc code=end
