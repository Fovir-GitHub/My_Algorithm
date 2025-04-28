/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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

class Solution
{
private:
    vector<int> result;
    int         max_mode      = 0;
    int         current_value = -1;
    int         frequence     = 0;

public:
    vector<int> findMode(TreeNode * root)
    {
        Traverse(root);
        return result;
    }

    void Traverse(TreeNode * node)
    {
        if (!node)
            return;

        Traverse(node->left);

        if (current_value == node->val)
            frequence++;
        else
        {
            current_value = node->val;
            frequence     = 1;
        }

        if (frequence > max_mode)
        {
            max_mode = frequence;
            result   = {node->val};
        }
        else if (frequence == max_mode)
            result.push_back(node->val);

        Traverse(node->right);
    }
};
// @lc code=end
