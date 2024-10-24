#ifndef _AVLTREE_HPP_
#define _AVLTREE_HPP_

#include<algorithm>

template<typename T>
class AvlTree
{
private:
    struct TreeNode
    {
        T value;
        int height = 0;
        TreeNode * left, * right;
    };

    TreeNode * root;

public:
    AvlTree();

    int Height(TreeNode * node)const { return node == nullptr ? -1 : node->height; }
    void UpdateHeight(TreeNode * node);
    int BalanceFactor(TreeNode * node);

    TreeNode * RightRotate(TreeNode * node);
    TreeNode * LeftRotate(TreeNode * node);
    TreeNode * Rotate(TreeNode * node);

    void insert(T insert_value) { root = InsertHelper(root, insert_value); }
    TreeNode * InsertHelper(TreeNode * node, T insert_value);

    void remove(T remove_value) { root = RemoveHelper(root, remove_value); }
    TreeNode * RemoveHelper(TreeNode * node, T remove_value);

    void traverse(void(*func)(T)) { return TraverseHelper(func, root); }
    void TraverseHelper(void(*func)(T), TreeNode * node);
};

template<typename T>
AvlTree<T>::AvlTree()
{
    root = nullptr;
}

template<typename T>
void AvlTree<T>::UpdateHeight(TreeNode * node)
{
    node->height = std::max(Height(node->left), Height(node->right)) + 1;
    return;
}

template<typename T>
int AvlTree<T>::BalanceFactor(TreeNode * node)
{
    if (node == nullptr)
        return 0;

    return Height(node->left) - Height(node->right);
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::RightRotate(AvlTree<T>::TreeNode * node)
{
    TreeNode * child = node->left;
    TreeNode * grand_child = child->right;

    node->left = grand_child;
    child->right = node;

    UpdateHeight(node);
    UpdateHeight(child);

    return child;
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::LeftRotate(AvlTree<T>::TreeNode * node)
{
    TreeNode * child = node->right;
    TreeNode * grand_child = child->left;

    node->right = grand_child;
    child->left = node;

    UpdateHeight(node);
    UpdateHeight(child);

    return child;
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::Rotate(AvlTree<T>::TreeNode * node)
{
    int balance_factor = BalanceFactor(node);

    if (balance_factor > 1)
    {
        if (BalanceFactor(node->left) >= 0)
            return RightRotate(node);
        else
        {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }
    }

    if (balance_factor < -1)
    {
        if (BalanceFactor(node->right) <= 0)
            return LeftRotate(node);
        else
        {
            node->left = RightRotate(node->left);
            return LeftRotate(node);
        }
    }

    return node;
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::InsertHelper(AvlTree<T>::TreeNode * node,
    T insert_value)
{
    if (node == nullptr)
    {
        TreeNode * return_node = new TreeNode;
        return_node->value = insert_value;
        return return_node;
    }

    if (insert_value < node->value)
        node->left = InsertHelper(node->left, insert_value);
    else if (insert_value > node->value)
        node->right = InsertHelper(node->right, insert_value);
    else
        return node;

    UpdateHeight(node);
    node = Rotate(node);

    return node;
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::RemoveHelper(AvlTree<T>::TreeNode * node,
    T remove_value)
{
    if (node == nullptr)
        return nullptr;

    if (remove_value < node->value)
        node->left = RemoveHelper(node->left, remove_value);
    else if (remove_value > node->value)
        node->right = RemoveHelper(node->right, remove_value);
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            TreeNode * child =
                (node->left != nullptr ? node->left : node->right);

            if (child == nullptr)
            {
                delete node;
                return nullptr;
            }
            else
            {
                delete node;
                node = child;
            }
        }
        else
        {
            TreeNode * temp = node->right;
            while (temp->left != nullptr)
                temp = temp->left;

            int temp_value = temp->value;
            node->right = RemoveHelper(node->right, temp->value);
            node->value = temp_value;
        }
    }

    UpdateHeight(node);
    node = Rotate(node);

    return node;
}

template<typename T>
void AvlTree<T>::TraverseHelper(void(*func)(T), TreeNode * node)
{
    if (node == nullptr)
        return;

    TraverseHelper(func, node->left);
    func(node->value);
    TraverseHelper(func, node->right);

    return;
}

#endif // !_AVLTREE_HPP_