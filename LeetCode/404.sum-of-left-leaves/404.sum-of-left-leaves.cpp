/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
public:
    // int sumOfLeftLeaves(TreeNode * root)
    // {
    //     int result = 0;
    //     Helper(root, result, false);

    //     return result;
    // }

    // void Helper(TreeNode * node, int & result, bool is_left)
    // {
    //     if (!node)
    //         return;

    //     if (is_left && !node->left && !node->right)
    //     {
    //         result += node->val;
    //         return;
    //     }

    //     Helper(node->left, result, true);
    //     Helper(node->right, result, false);

    //     return;
    // }

    int sumOfLeftLeaves(TreeNode * root, bool is_left = false) {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return is_left ? root->val : 0;

        return sumOfLeftLeaves(root->left, true) +
               sumOfLeftLeaves(root->right, false);
    }
};
// @lc code=end
