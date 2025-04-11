#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <functional>
#include <memory>

template <typename T>
struct LinkedListNode
{
    std::shared_ptr<LinkedListNode> next;
    T                               value;

    LinkedListNode() : next(nullptr) {}
    LinkedListNode(T val) : next(nullptr), value(val) {}
    LinkedListNode(std::shared_ptr<LinkedListNode<T>> ne, T val)
        : next(ne)
        , value(val)
    {
    }
};

template <typename T>
class LinkedList
{
private:
    using Node = LinkedListNode<T>;
    std::shared_ptr<LinkedListNode<T>> root;

public:
    LinkedList() : root(nullptr) {}
    ~LinkedList() {}

    void Insert(
        T                                         insert_value,
        std::function<bool(const T &, const T &)> compare_function =
            [](const T & first, const T & second) { return first <= second; });

    void Append(T append_value);

    std::shared_ptr<LinkedListNode<T>> Find(T find_value);

    void Traverse(std::function<void(const T &)> func);

    void PopFront();
};

#endif // !_LINKEDLIST_H_

template <typename T>
void LinkedList<T>::Insert(
    T insert_value, std::function<bool(const T &, const T &)> compare_function)
{
    if (!root || compare_function(root->value, insert_value))
    {
        root = std::make_shared<Node>(root, insert_value);
        return;
    }

    for (std::shared_ptr<Node> current = root; current; current = current->next)
        if (current->value == insert_value)
            return;
        else if (compare_function(current->value, insert_value))
        {
            current->next = std::make_shared<Node>(current->next, insert_value);
            return;
        }
}

template <typename T>
void LinkedList<T>::Append(T append_value)
{
    if (!root)
    {
        root = std::make_shared<Node>(append_value);
        return;
    }

    std::shared_ptr<Node> current = root;
    while (current->next) current = current->next;

    current->next = std::make_shared<Node>(append_value);
}

template <typename T>
std::shared_ptr<LinkedListNode<T>> LinkedList<T>::Find(T find_value)
{
    for (std::shared_ptr<Node> current = root; current; current = current->next)
        if (current->value == find_value)
            return current;

    return nullptr;
}

template <typename T>
void LinkedList<T>::Traverse(std::function<void(const T &)> func)
{
    for (std::shared_ptr<Node> current = root; current; current = current->next)
        func(current->value);

    return;
}

template <typename T>
void LinkedList<T>::PopFront()
{
    if (!root)
        return;

    root = root->next;
}
