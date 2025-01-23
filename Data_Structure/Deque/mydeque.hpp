#ifndef _MYDEQUE_HPP_
#define _MYDEQUE_HPP_

template <typename T> class MyDeque
{
private:
    enum { FRONT = 0, BACK = 1 };

    struct Node
    {
        Node *front, *next;
        T value;
    };

    Node *head, *rear;
    unsigned int node_count;

public:
    MyDeque();
    ~MyDeque();

    unsigned int size() const { return node_count; }
    bool empty() const { return size() == 0; }

    bool push(T push_value, bool mode);
    bool push_front(T push_value) { return push(push_value, FRONT); }
    bool push_back(T push_value) { return push(push_value, BACK); }

    bool pop(bool mode);
    bool pop_front() { return pop(FRONT); }
    bool pop_back() { return pop(BACK); }

    T peek_front() { return empty() ? (T) 0 : head->value; }
    T peek_back() { return empty() ? (T) 0 : rear->value; }
};

template <typename T> MyDeque<T>::MyDeque() : node_count(0)
{
    head = new Node;
    rear = new Node;
    head->front = head->next = nullptr;
    rear->front = rear->next = nullptr;
}

template <typename T> MyDeque<T>::~MyDeque()
{
    while (head)
    {
        rear = head->next;
        delete head;
        head = rear;
    }
    node_count = 0;
}

template <typename T> bool MyDeque<T>::push(T push_value, bool mode)
{
    Node * push_node = new Node;
    if (!push_node)
        return false;

    push_node->value = push_value;
    push_node->next = push_node->front = nullptr;

    if (empty())
        head = rear = push_node;
    else if (mode == FRONT)
    {
        head->front = push_node;
        push_node->next = head;
        head = push_node;
    }
    else
    {
        rear->next = push_node;
        push_node->front = rear;
        rear = push_node;
    }

    ++node_count;

    return true;
}

template <typename T> bool MyDeque<T>::pop(bool mode)
{
    if (empty())
        return false;

    Node * backup;

    if (size() == 1)
    {
        delete head;
        head = rear = nullptr;
    }
    else if (mode == FRONT)
    {
        backup = head->next;
        delete head;
        head = backup;
        head->front = nullptr;
    }
    else
    {
        backup = rear->front;
        delete rear;
        rear = backup;
        rear->next = nullptr;
    }

    --node_count;

    return true;
}

#endif // !_MYDEQUE_HPP_