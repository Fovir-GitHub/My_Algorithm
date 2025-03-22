/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

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
public:
    vector<int> postorderTraversal(TreeNode * root)
    {
        vector<int> result;
        postorderTraversalHelper(root, result);

        return result;
    }

    void postorderTraversalHelper(TreeNode * node, vector<int> & result)
    {
        if (!node)
            return;

        postorderTraversalHelper(node->left, result);
        postorderTraversalHelper(node->right, result);
        result.push_back(node->val);

        return;
    }
};
// @lc code=end
