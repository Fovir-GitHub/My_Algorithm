#ifndef _BINARYTREE_HPP_
#define _BINARYTREE_HPP_

template<typename T>
class MyBinaryTree
{
private:
    struct TreeNode
    {
        TreeNode * left, * right;
        T value;
    };

    TreeNode * root;
    unsigned int tree_node_counter;

public:
    MyBinaryTree();

    unsigned int size()const { return tree_node_counter; }
    bool empty()const { return size() == 0; }
    TreeNode * GetRootNode()const { return root; }

    void insert(T insert_value);
    void traverse(void(*func)(T &), TreeNode * start_node);
};

template<typename T>
MyBinaryTree<T>::MyBinaryTree() :tree_node_counter(0)
{
    root = new TreeNode;
    root->left = root->right = nullptr;
}

template<typename T>
void MyBinaryTree<T>::insert(T insert_value)
{
    if (empty())
    {
        root->value = insert_value;
        ++tree_node_counter;
        return;
    }
    TreeNode * insert_node = new TreeNode;
    if (!insert_node)
        return;

    insert_node->left = insert_node->right = nullptr;
    insert_node->value = insert_value;
    TreeNode * visit = root;
    while (true)
    {
        if (insert_value < visit->value)
        {
            if (visit->left == nullptr)
            {
                visit->left = insert_node;
                return;
            }
            else
                visit = visit->left;
        }
        else if (insert_value > visit->value)
        {
            if (visit->right == nullptr)
            {
                visit->right = insert_node;
                return;
            }
            else
                visit = visit->right;
        }
        else
        {
            delete insert_node;
            return;
        }
    }
    ++tree_node_counter;

    return;
}

template<typename T>
void MyBinaryTree<T>::traverse(void(*func)(T &), TreeNode * start_node)
{
    if (start_node == nullptr)
        return;

    traverse(func, start_node->left);
    func(start_node->value);
    traverse(func, start_node->right);

    return;
}

#endif // !_BINARYTREE_HPP_