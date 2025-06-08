/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

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

class Solution {
private:
    TreeNode * original_subroot;

public:
    bool isSubtree(TreeNode * root, TreeNode * subRoot) {
        original_subroot = subRoot;
        return isSubtreeHelper(root, subRoot);
    }

    bool isSubtreeHelper(TreeNode * root, TreeNode * subRoot) {
        if (!root || !subRoot)
            return !root && !subRoot;

        if (root->val == subRoot->val && root->val == original_subroot->val)
            return ((isSubtreeHelper(root->left, subRoot->left) &&
                     isSubtreeHelper(root->right, subRoot->right))) ||
                   (isSubtreeHelper(root->left, original_subroot->left) &&
                    isSubtreeHelper(root->right, original_subroot->right));
        else if (root->val == subRoot->val)
            return (isSubtreeHelper(root->left, subRoot->left) &&
                    isSubtreeHelper(root->right, subRoot->right));
        else
            return isSubtreeHelper(root->left, original_subroot) ||
                   isSubtreeHelper(root->right, original_subroot);
    }
};
// @lc code=end
