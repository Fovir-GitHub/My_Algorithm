#ifndef _LINKLIST_H_
#define _LINKLIST_H_

template <typename T> class LinkList
{
private:
    struct Node
    {
        T value;
        Node * next;
    };

    Node * root; /* The root of the link list */
    Node * now;  /* The last Node position */
    unsigned int node_count;

public:
    LinkList();
    ~LinkList();

    bool push(T push_value);
    bool insert(T insert_value, unsigned int target_position);
    bool remove(unsigned int remove_position);
    bool find(T target);

    void access(void (*func)(T));
    int size() { return node_count; }
};

template <typename T> LinkList<T>::LinkList()
{
    root = new Node;
    root->next = nullptr;
    now = root;
    node_count = 0;
}

template <typename T> LinkList<T>::~LinkList()
{
    Node * backup;

    while (root)
    {
        backup = root->next;
        delete root;
        root = backup;
    }
    node_count = 0;
}

template <typename T> bool LinkList<T>::push(T push_value)
{
    Node * push_node = new Node;
    if (!push_node)
        return false;

    push_node->next = nullptr;
    push_node->value = push_value;

    if (root->next == nullptr) /* No element */
        root->next = push_node;
    else
        now->next = push_node;

    now = push_node;
    ++node_count;

    return true;
}

template <typename T>
bool LinkList<T>::insert(T insert_value, unsigned int target_position)
{
    target_position = std::min(target_position, node_count);
    unsigned int position_count = 0;
    Node * current = root;

    while (position_count++ != target_position) current = current->next;

    Node * insert_node = new Node;
    if (!insert_node)
        return false;

    insert_node->value = insert_value;
    insert_node->next = current->next;
    current->next = insert_node;
    ++node_count;

    return true;
}

template <typename T> bool LinkList<T>::remove(unsigned int remove_position)
{
    remove_position = std::min(remove_position, node_count - 1);

    Node * current = root;
    unsigned int position_count = 0;

    while (position_count++ != remove_position) current = current->next;

    if (!current)
        return false;

    Node * backup_next = current->next;
    current->next = backup_next->next;

    delete backup_next;
    --node_count;

    return true;
}

template <typename T> bool LinkList<T>::find(T target)
{
    Node * temp = root;

    while (temp = temp->next)
        if (temp->value == target)
            return true;

    return false;
}

template <typename T> void LinkList<T>::access(void (*func)(T))
{
    Node * temp = root;

    while (temp = temp->next) func(temp->value);

    return;
}

#endif // !_LINKLIST_H_