/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include <bits/stdc++.h>
using namespace std;

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
//     TreeNode()
//         : val(0)
//         , left(nullptr)
//         , right(nullptr)
//     {
//     }
//     TreeNode(int x)
//         : val(x)
//         , left(nullptr)
//         , right(nullptr)
//     {
//     }
//     TreeNode(int x, TreeNode * left, TreeNode * right)
//         : val(x)
//         , left(left)
//         , right(right)
//     {
//     }
// };

class Solution {
public:
    bool isBalanced(TreeNode * root) { return height(root) != -1; }

    int height(TreeNode * node) {
        if (!node)
            return 0;

        int left = height(node->left);
        if (left == -1)
            return -1;

        int right = height(node->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }
};
// @lc code=end
