/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int        min_diff = INT_MAX;
    TreeNode * previous = nullptr;

public:
    int getMinimumDifference(TreeNode * root)
    {
        dfs(root);
        return min_diff;
    }

    void dfs(TreeNode * node)
    {
        if (!node)
            return;

        dfs(node->left);

        if (previous)
            min_diff = min(min_diff, abs(previous->val - node->val));
        previous = node;

        dfs(node->right);

        return;
    }
};
// @lc code=end
