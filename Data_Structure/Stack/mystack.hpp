#ifndef _MYSTACK_HPP_
#define _MYSTACK_HPP_

template<typename T>
class MyStack
{
private:
    struct Node
    {
        T value;
        Node * next;
        Node * front;
    };
    Node * tail;
    Node * root;
    unsigned int node_count;

public:
    MyStack();
    ~MyStack();

    bool push(T push_value);
    bool pop();
    T peek() { return !empty() ? tail->value : (T) 0; }
    unsigned int size() { return node_count; }
    bool empty() { return !node_count; }
};

template<typename T>
MyStack<T>::MyStack()
{
    root = new Node;
    root->next = root->front = nullptr;
    tail = root;
    node_count = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
    while (root)
    {
        tail = root->next;
        delete root;
        root = tail;
    }
    node_count = 0;
}

template<typename T>
bool MyStack<T>::push(T push_value)
{
    Node * push_node = new Node;
    if (!push_node)
        return false;

    push_node->next = nullptr;
    push_node->value = push_value;
    push_node->front = tail;
    tail->next = push_node;
    tail = push_node;
    ++node_count;

    return true;
}

template<typename T>
bool MyStack<T>::pop()
{
    if (node_count == 0)
        return false;

    Node * backup_tail = tail;
    tail = tail->front;
    tail->next = nullptr;
    delete backup_tail;

    --node_count;

    return true;
}

#endif // !_MYSTACK_HPP_