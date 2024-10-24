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
        TreeNode * left;
        TreeNode * right;

        TreeNode(int val) :value(val) {}
    };

    TreeNode * root;

public:
    AvlTree() { root = nullptr; }

    int GetHeight(const TreeNode * node)const { return node == nullptr ? -1 : node->height; }
    void UpdateHeight(TreeNode * node);
    int GetBalanceFactor(TreeNode * node);

    TreeNode * LeftRotate(TreeNode * node);
    TreeNode * RightRotate(TreeNode * node);
    TreeNode * Rotate(TreeNode * node);

    void insert(T insert_value) { root = InsertHelper(root, insert_value); }
    TreeNode * InsertHelper(TreeNode * node, T insert_value);

    void remove(T remove_value) { root = RemoveHelper(root, remove_value); }
    TreeNode * RemoveHelper(TreeNode * node, T remove_value);

    void traverse(void(*func)(T)) { return TraverseHelper(root, func); }
    void TraverseHelper(TreeNode * node, void(*func)(T));

    bool find(T find_value)const;
};

template<typename T>
void AvlTree<T>::UpdateHeight(typename AvlTree<T>::TreeNode * node)
{
    node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::LeftRotate(typename AvlTree<T>::TreeNode * node)
{
    TreeNode * child = node->right;
    TreeNode * grand_child = child->left;

    child->left = node;
    node->right = grand_child;

    UpdateHeight(node);
    UpdateHeight(child);

    return child;
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::RightRotate(typename AvlTree<T>::TreeNode * node)
{
    TreeNode * child = node->left;
    TreeNode * grand_child = child->right;

    child->right = node;
    node->left = grand_child;

    UpdateHeight(node);
    UpdateHeight(child);

    return child;
}

template<typename T>
int AvlTree<T>::GetBalanceFactor(typename AvlTree<T>::TreeNode * node)
{
    if (node == nullptr)
        return 0;

    return GetHeight(node->left) - GetHeight(node->right);
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::Rotate(typename AvlTree<T>::TreeNode * node)
{
    int balance_factor = GetBalanceFactor(node);

    if (balance_factor > 1)
    {
        if (GetBalanceFactor(node->left) >= 0)
            return RightRotate(node);
        else
        {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }
    }

    if (balance_factor < -1)
    {
        if (GetBalanceFactor(node->right) <= 0)
            return LeftRotate(node);
        else
        {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }
    }

    return node;
}

template<typename T>
typename AvlTree<T>::TreeNode * AvlTree<T>::InsertHelper(
    typename AvlTree<T>::TreeNode * node, T insert_value
)
{
    if (node == nullptr)
        return new TreeNode(insert_value);

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
typename AvlTree<T>::TreeNode * AvlTree<T>::RemoveHelper(
    typename AvlTree<T>::TreeNode * node, T remove_value
)
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
            while (temp->left)
                temp = temp->left;

            T temp_value = temp->value;
            node->right = RemoveHelper(node->right, temp_value);
            node->value = temp_value;
        }
    }
    UpdateHeight(node);
    node = Rotate(node);

    return node;
}

template<typename T>
void AvlTree<T>::TraverseHelper(typename AvlTree<T>::TreeNode * node, void(*func)(T))
{
    if (node == nullptr)
        return;

    TraverseHelper(node->left, func);
    func(node->value);
    TraverseHelper(node->right, func);

    return;
}

template<typename T>
bool AvlTree<T>::find(T find_value) const
{
    TreeNode * node = root;

    while (node)
    {
        if (find_value == node->value)
            return true;

        if (find_value < node->value)
            node = node->left;
        else
            node = node->right;
    }

    return false;
}

#endif // !_AVLTREE_HPP_