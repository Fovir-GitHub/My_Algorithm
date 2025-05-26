/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

// struct TreeNode
// {
//     int        val;
//     TreeNode * left;
//     TreeNode * right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode * left, TreeNode * right)
//         : val(x)
//         , left(left)
//         , right(right)
//     {
//     }
// };

class Solution
{
private:
    int tilt_sum = 0;

public:
    int findTilt(TreeNode * root)
    {
        findTiltHelper(root);
        return tilt_sum;
    }

    int findTiltHelper(TreeNode * root)
    {
        if (!root)
            return 0;

        int left_sum  = findTiltHelper(root->left),
            right_sum = findTiltHelper(root->right);
        tilt_sum += std::abs(left_sum - right_sum);

        return left_sum + right_sum + root->val;
    }
};
// @lc code=end
