/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

#include <bits/stdc++.h>
using namespace std;

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
    int result = 0;

public:
    int diameterOfBinaryTree(TreeNode * root) {
        dfs(root);

        return result;
    }

    int dfs(TreeNode * node) {
        if (!node)
            return 0;

        int left = dfs(node->left), right = dfs(node->right);

        result = max(result, left + right);

        return 1 + max(left, right);
    }
};
// @lc code=end
