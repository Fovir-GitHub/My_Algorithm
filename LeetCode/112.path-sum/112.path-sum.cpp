/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// struct TreeNode
// {
//     int val;
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
public:
    bool hasPathSum(TreeNode * root, int targetSum)
    {
        return dfs(root, 0, targetSum);
    }

    bool dfs(TreeNode * node, int current_sum, int & target)
    {
        if (!node)
            return false;

        current_sum += node->val;
        if (!node->left && !node->right)
            return current_sum == target;

        return dfs(node->left, current_sum, target) ||
               dfs(node->right, current_sum, target);
    }
};
// @lc code=end
