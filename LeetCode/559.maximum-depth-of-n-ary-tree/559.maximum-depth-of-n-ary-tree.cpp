/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

// class Node
// {
// public:
//     int            val;
//     vector<Node *> children;

//     Node() {}

//     Node(int _val) { val = _val; }

//     Node(int _val, vector<Node *> _children)
//     {
//         val      = _val;
//         children = _children;
//     }
// };

class Solution {
public:
    // int maxDepth(Node * root)
    // {
    //     if (!root)
    //         return 0;

    //     int max_depth = 0;
    //     for (Node * node : root->children)
    //         max_depth = max(max_depth, maxDepth(node));

    //     return max_depth + 1;
    // }

    int maxDepth(Node * root) {
        if (!root)
            return 0;

        queue<Node *> que;
        int depth = 0;
        que.push(root);

        while (!que.empty()) {
            depth++;

            int queue_size = que.size();
            for (int i = 0; i < queue_size; i++) {
                Node * node = que.front();
                que.pop();

                for (Node * child : node->children)
                    que.push(child);
            }
        }

        return depth;
    }
};
// @lc code=end
