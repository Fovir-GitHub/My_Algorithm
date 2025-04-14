#ifndef _DOUBLYLINKEDLIST_HPP_
#define _DOUBLYLINKEDLIST_HPP_

#include <functional>
#include <memory>

#define DOUBLYLINKEDLIST_NAMESPACE_BEGIN \
    namespace doublylinkedlist           \
    {
#define DOUBLYLINKEDLIST_NAMESPACE_END }

DOUBLYLINKEDLIST_NAMESPACE_BEGIN

template <typename T>
struct DoublyLinkedListNode
{
    std::shared_ptr<DoublyLinkedListNode<T>> previous;
    std::weak_ptr<DoublyLinkedListNode<T>>   next;
    T                                        value;

    DoublyLinkedListNode() : previous(nullptr) {}
    DoublyLinkedListNode(const T & val) : previous(nullptr), value(val) {}
};

template <typename T>
class DoublyLinkedList
{
private:
    using Node = DoublyLinkedListNode<T>;

    std::shared_ptr<Node> head, tail;
    size_t                size;

    void Traverse(std::function<void(const T &)> func, bool front);

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList() {}

    size_t Size() const { return size; }
    bool   Empty() const { return Size() == 0; }

    void PushFront(const T & push_value);
    void PushBack(const T & push_value);

    const T & PeekFront() const { return head->value; }
    const T & PeekBack() const { return tail->value; }

    void PopFront();
    void PopBack();

    void TraverseFront(std::function<void(const T &)> func)
    {
        Traverse(func, true);
    }

    void TraverseBack(std::function<void(const T &)> func)
    {
        Traverse(func, false);
    }
};

DOUBLYLINKEDLIST_NAMESPACE_END

#endif // !_DOUBLYLINKEDLIST_HPP_

template <typename T>
void doublylinkedlist::DoublyLinkedList<T>::Traverse(
    std::function<void(const T &)> func, bool front)
{
    for (std::shared_ptr<Node> current = front ? head : tail; current;
         current = front ? current->next.lock() : current->previous)
        func(current->value);

    return;
}

template <typename T>
void doublylinkedlist::DoublyLinkedList<T>::PushFront(const T & push_value)
{
    std::shared_ptr<Node> new_node = std::make_shared<Node>(push_value);
    new_node->next                 = head;

    if (head)
        head->previous = new_node;

    head = new_node;

    if (!tail)
        tail = head;

    size++;

    return;
}

template <typename T>
void doublylinkedlist::DoublyLinkedList<T>::PushBack(const T & push_value)
{
    std::shared_ptr<Node> new_node = std::make_shared<Node>(push_value);
    new_node->previous             = tail;

    if (tail)
        tail->next = new_node;

    tail = new_node;

    if (!head)
        head = tail;

    size++;

    return;
}

template <typename T>
void doublylinkedlist::DoublyLinkedList<T>::PopFront()
{
    if (Empty())
        return;

    head = head->next.lock();
    if (head)
        head->previous.reset();
    else
        tail = nullptr;

    size--;

    return;
}

template <typename T>
void doublylinkedlist::DoublyLinkedList<T>::PopBack()
{
    if (Empty())
        return;

    std::shared_ptr<Node> previous = tail->previous;

    if (previous)
        previous->next.reset();

    tail = previous;

    if (!tail)
        head.reset();

    size--;

    return;
}
