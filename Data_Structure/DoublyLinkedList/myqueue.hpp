#ifndef _MYQUEUE_HPP_
#define _MYQUEUE_HPP_

#include "doublylinkedlist.hpp"

#define MYQUEUE_NAMESPACE_BEGIN namespace myqueue {
#define MYQUEUE_NAMESPACE_END }

MYQUEUE_NAMESPACE_BEGIN

template <typename T>
class Queue : private doublylinkedlist::DoublyLinkedList<T> {
public:
    Queue() : doublylinkedlist::DoublyLinkedList<T>() {}
    ~Queue() {}

    void Push(const T & value) { this->PushBack(value); }
    const T & Front() const { return this->PeekFront(); }
    void Pop() { return this->PopFront(); }

    size_t Size() const {
        return doublylinkedlist::DoublyLinkedList<T>::Size();
    }

    bool Empty() const {
        return doublylinkedlist::DoublyLinkedList<T>::Empty();
    }
};

MYQUEUE_NAMESPACE_END

#endif // !_MYQUEUE_HPP_