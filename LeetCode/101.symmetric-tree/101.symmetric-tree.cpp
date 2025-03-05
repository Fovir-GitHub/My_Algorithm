/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

struct TreeNode
{
    int        val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode * left, TreeNode * right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution
{
public:
    bool isSymmetric(TreeNode * root)
    {
        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode * left_node, TreeNode * right_node)
    {
        if (!left_node || !right_node)
            return !left_node && !right_node;

        if (!isSymmetricHelper(left_node->left, right_node->right) ||
            !isSymmetricHelper(left_node->right, right_node->left))
            return false;
        else
            return left_node->val == right_node->val;
    }
};
// @lc code=end
