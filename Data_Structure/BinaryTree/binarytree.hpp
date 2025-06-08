#ifndef _BINARYTREE_HPP_
#define _BINARYTREE_HPP_

#include <iostream>

template <typename T> class MyBinaryTree {
private:
    struct TreeNode {
        TreeNode *left, *right;
        T value;
    };

    TreeNode * root;
    unsigned int tree_node_counter;

public:
    MyBinaryTree();

    unsigned int size() const { return tree_node_counter; }
    bool empty() const { return size() == 0; }
    TreeNode * GetRootNode() const { return root; }

    void insert(T insert_value);
    void traverse(void (*func)(T), TreeNode * start_node);
    void remove(T remove_value);
    bool find(T find_value);
};

template <typename T> MyBinaryTree<T>::MyBinaryTree() : tree_node_counter(0) {
    root = new TreeNode;
    root->left = root->right = nullptr;
}

template <typename T> void MyBinaryTree<T>::insert(T insert_value) {
    if (empty()) {
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
    while (true) {
        if (insert_value < visit->value) {
            if (visit->left == nullptr) {
                visit->left = insert_node;
                break;
            } else
                visit = visit->left;
        } else if (insert_value > visit->value) {
            if (visit->right == nullptr) {
                visit->right = insert_node;
                break;
            } else
                visit = visit->right;
        } else {
            delete insert_node;
            return;
        }
    }
    ++tree_node_counter;

    return;
}

template <typename T>
void MyBinaryTree<T>::traverse(void (*func)(T), TreeNode * start_node) {
    if (start_node == nullptr)
        return;

    traverse(func, start_node->left);
    func(start_node->value);
    traverse(func, start_node->right);

    return;
}

template <typename T> void MyBinaryTree<T>::remove(T remove_value) {
    if (empty())
        return;

    TreeNode *current = root, *previous = nullptr;

    while (current != nullptr) {
        if (current->value == remove_value)
            break;
        previous = current;
        if (current->value < remove_value)
            current = current->right;
        else
            current = current->left;
    }

    if (current == nullptr)
        return;

    if (current->left == nullptr || current->right == nullptr) {
        TreeNode * child =
            (current->left != nullptr ? current->left : current->right);

        if (current != root) {
            if (previous->left == current)
                previous->left = child;
            else
                previous->right = child;
        } else
            root = child;

        --tree_node_counter;
        delete current;
    } else {
        TreeNode * tmp = current->right;
        while (tmp->left != nullptr)
            tmp = tmp->left;

        T tmpVal = tmp->value;
        remove(tmp->value);
        current->value = tmpVal;
    }

    return;
}

template <typename T> bool MyBinaryTree<T>::find(T find_value) {
    TreeNode * visit = root;
    while (visit) {
        if (visit->value == find_value)
            return true;

        if (find_value < visit->value)
            visit = visit->left;
        else
            visit = visit->right;
    }

    return false;
}

#endif // !_BINARYTREE_HPP_
