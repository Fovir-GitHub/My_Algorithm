/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

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
    vector<string> binaryTreePaths(TreeNode * root) {
        vector<string> result;

        if (root)
            dfs(root, result, "");

        return result;
    }

    void dfs(TreeNode * node, vector<string> & result, string temp) {
        temp += to_string(node->val);
        if (node->left)
            dfs(node->left, result, temp + "->");
        if (node->right)
            dfs(node->right, result, temp + "->");

        if (!node->left && !node->right)
            result.push_back(temp);

        return;
    }
};
// @lc code=end
