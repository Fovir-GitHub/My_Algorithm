/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> result;
        traverseTree(root, result);

        return result;
    }

    void traverseTree(TreeNode * node, vector<int> & result) {
        if (!node)
            return;

        traverseTree(node->left, result);
        result.push_back(node->val);
        traverseTree(node->right, result);
    }
};
// @lc code=end
