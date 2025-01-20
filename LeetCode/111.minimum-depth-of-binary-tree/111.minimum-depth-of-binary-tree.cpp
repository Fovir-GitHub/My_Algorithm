/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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

class Solution
{
public:
    // int min_depth = INT_MAX;

    // int minDepth(TreeNode * root)
    // {
    //     if (!root)
    //         return 0;

    //     root->val = 1;
    //     helper(root);

    //     return min_depth;
    // }

    // void helper(TreeNode * node)
    // {
    //     if (!node)
    //         return;

    //     if (node->left || node->right)
    //     {
    //         if (node->left)
    //             node->left->val = node->val + 1;
    //         if (node->right)
    //             node->right->val = node->val + 1;
    //     }
    //     else
    //     {
    //         min_depth = min(min_depth, node->val);
    //         return;
    //     }

    //     helper(node->left);
    //     helper(node->right);
    // }

    int minDepth(TreeNode * root)
    {
        if (!root)
            return 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});

        while (!q.empty())
        {
            auto [node, depth] = q.front();
            q.pop();

            if (!node->left && !node->right)
                return depth;

            if (node->left)
                q.push({node->left, depth + 1});
            if (node->right)
                q.push({node->right, depth + 1});
        }

        return 0;
    }
};
// @lc code=end
