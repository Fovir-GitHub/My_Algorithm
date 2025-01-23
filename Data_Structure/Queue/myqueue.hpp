#ifndef _MYQUEUE_HPP_
#define _MYQUEUE_HPP_

template <typename T> class MyQueue
{
private:
    struct Node
    {
        Node * next;
        T value;
    };

    Node * root;
    Node * tail;
    unsigned int node_count;

public:
    MyQueue();
    ~MyQueue();

    bool push(T push_value);
    bool pop();
    bool empty() { return !node_count; }
    T peek() { return !empty() ? root->next->value : (T) 0; }
    unsigned int size() { return node_count; }
};

template <typename T> MyQueue<T>::MyQueue() : node_count(0)
{
    root = new Node;
    root->next = nullptr;
    tail = root;
}

template <typename T> MyQueue<T>::~MyQueue()
{
    while (root)
    {
        tail = root->next;
        delete root;
        root = tail;
    }
}

template <typename T> bool MyQueue<T>::push(T push_value)
{
    Node * push_node = new Node;
    if (!push_node)
        return false;

    push_node->value = push_value;
    push_node->next = nullptr;

    if (!root->next)
        root->next = push_node;
    else
        tail->next = push_node;

    tail = push_node;
    ++node_count;

    return true;
}

template <typename T> bool MyQueue<T>::pop()
{
    if (empty())
        return false;

    Node * backup_node = root->next;
    root->next = backup_node->next;
    delete backup_node;
    --node_count;

    return true;
}

#endif // !_MYQUEUE_HPP_