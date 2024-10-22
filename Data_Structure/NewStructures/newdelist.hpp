#ifndef _NEWDELIST_HPP_
#define _NEWDELIST_HPP_

template<typename T>
class NewDeList
{
private:
    struct Node
    {
        Node * previous, * next;
        T value;
    };

    Node * head, * rear;
    unsigned int node_counter;

public:
    NewDeList();
    ~NewDeList();

    unsigned int size()const { return node_counter; }
    bool empty()const { return size() == 0; }

    virtual bool push(T push_value, bool mode);
    bool push_front(T push_value) { return push(push_value, FRONT); }
    bool push_back(T push_value) { return push(push_value, BACK); }

    virtual bool pop(bool mode);
    bool pop_front() { return pop(FRONT); }
    bool pop_back() { return pop(BACK); }

    virtual T peek(bool mode)const;
    T peek_front()const { return peek(FRONT); }
    T peek_back()const { return peek(BACK); }

protected:
    enum { FRONT = 0, BACK = 1 };
};

template<typename T>
NewDeList<T>::NewDeList() :node_counter(0)
{
    head = new Node;
    rear = new Node;
    head->previous = head->next = nullptr;
    rear->previous = rear->next = nullptr;
}

template<typename T>
NewDeList<T>::~NewDeList()
{
    while (head)
    {
        rear = head->next;
        delete head;
        head = rear;
    }
    head = rear = nullptr;
    node_counter = 0;
}

template<typename T>
bool NewDeList<T>::push(T push_value, bool mode)
{
    Node * push_node = new Node;
    if (!push_node)
        return false;

    push_node->value = push_value;
    push_node->previous = push_node->next = nullptr;

    if (empty())
        head = rear = push_node;
    else if (mode == FRONT)
    {
        head->previous = push_node;
        push_node->next = head;
        head = push_node;
    }
    else
    {
        rear->next = push_node;
        push_node->previous = rear;
        rear = push_node;
    }

    ++node_counter;
    return true;
}

template<typename T>
bool NewDeList<T>::pop(bool mode)
{
    Node * backup_node;

    if (empty())
        return false;

    if (size() == 1)
    {
        delete head;
        head = rear = nullptr;
    }
    else if (mode == FRONT)
    {
        backup_node = head;
        head = head->next;
        delete backup_node;
    }
    else
    {
        backup_node = rear;
        rear = rear->previous;
        delete backup_node;
    }

    --node_counter;

    return true;
}

template<typename T>
T NewDeList<T>::peek(bool mode)const
{
    if (empty())
        return (T) 0;

    if (mode == FRONT)
        return head->value;
    else
        return rear->value;
}

#endif // !_NEWDELIST_HPP_