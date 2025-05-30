#include <iostream>
#include <utility>
#include <vector>

struct TreeNode
{
    int       value;
    TreeNode *left, *right;

    TreeNode() : left(nullptr), right(nullptr), value(0) {}
    TreeNode(int val) : left(nullptr), right(nullptr), value(val) {}
};

void       MakeTree(TreeNode *& root, std::vector<int> & numbers);
TreeNode * InsertHelper(TreeNode * node, int value);
void       ShowTree(TreeNode * node);

class Solution
{
private:
    std::pair<TreeNode *, TreeNode *> PostOrder(TreeNode * node);

public:
    TreeNode * bstToDoublyLinkedList(TreeNode * root)
    {
        return PostOrder(root).first;
    }
};

void MakeTree(TreeNode *& root, std::vector<int> & numbers)
{
    root = new TreeNode(numbers[0]);

    for (int i = 1; i < numbers.size(); i++) InsertHelper(root, numbers[i]);

    return;
}

TreeNode * InsertHelper(TreeNode * node, int value)
{
    if (!node)
        return new TreeNode(value);

    if (node->value == value)
        return node;

    if (value < node->value)
        node->left = InsertHelper(node->left, value);
    else
        node->right = InsertHelper(node->right, value);

    return node;
}

void ShowTree(TreeNode * node)
{
    if (!node)
        return;

    ShowTree(node->left);
    std::cout << node->value << ' ';
    ShowTree(node->right);

    return;
}

int main(void)
{
    std::vector<int> data = {10, 6, 14, 4, 8, 12, 16};
    TreeNode *       tree = nullptr;
    Solution         sol;

    MakeTree(tree, data);

    tree = sol.bstToDoublyLinkedList(tree);

    for (; tree; tree = tree->right) std::cout << tree->value << ' ';
    std::cout << '\n';

    return 0;
}

std::pair<TreeNode *, TreeNode *> Solution::PostOrder(TreeNode * node)
{
    if (!node)
        return {nullptr, nullptr};

    auto [left_head, left_tail]   = PostOrder(node->left);
    auto [right_head, right_tail] = PostOrder(node->right);

    node->left = node->right = nullptr;
    if (left_tail)
    {
        left_tail->right = node;
        node->left       = left_tail;
    }

    if (right_head)
    {
        right_head->left = node;
        node->right      = right_head;
    }

    return {left_head ? left_head : node, right_tail ? right_tail : node};
}
