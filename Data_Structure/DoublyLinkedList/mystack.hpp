#ifndef _MYSTACK_HPP_
#define _MYSTACK_HPP_

#include "doublylinkedlist.hpp"

#define MYSTACK_NAMESPACE_BEGIN namespace mystack {
#define MYSTACK_NAMESPACE_END }

MYSTACK_NAMESPACE_BEGIN

template <typename T>
class Stack : private doublylinkedlist::DoublyLinkedList<T> {
public:
    Stack() : doublylinkedlist::DoublyLinkedList<T>() {}
    ~Stack() {}

    void Push(const T & push_value) { this->PushBack(push_value); }
    const T & Top() const { return this->PeekBack(); }
    void Pop() { this->PopBack(); }

    size_t Size() const {
        return doublylinkedlist::DoublyLinkedList<T>::Size();
    }

    bool Empty() const {
        return doublylinkedlist::DoublyLinkedList<T>::Empty();
    }
};

MYSTACK_NAMESPACE_END

#endif // !_MYSTACK_HPP_