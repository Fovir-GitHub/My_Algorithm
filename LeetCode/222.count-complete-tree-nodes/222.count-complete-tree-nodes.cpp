/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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

class Solution {
public:
    int countNodes(TreeNode * root) {
        if (!root)
            return 0;

        int left = 0, right = 0;
        TreeNode *left_node = root, *right_node = root;

        while (left_node) {
            left++;
            left_node = left_node->left;
        }

        while (right_node) {
            right++;
            right_node = right_node->right;
        }

        if (left == right)
            return (1 << left) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end
