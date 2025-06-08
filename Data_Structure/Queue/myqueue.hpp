#ifndef _MYQUEUE_HPP_
#define _MYQUEUE_HPP_

#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>

#define QUEUE_NAMESPACE_START namespace myqueue {
#define QUEUE_NAMESPACE_END }

QUEUE_NAMESPACE_START

template <typename T> struct Node {
    std::shared_ptr<Node<T>> next;
    T value;

    Node() : next(nullptr) {}
    Node(const T & val) : value(val), next(nullptr) {}
};

template <typename T> class Queue {
private:
    std::shared_ptr<Node<T>> head, tail;
    int size;

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}
    ~Queue() {}

    bool Empty() const { return size == 0; }
    int Size() const { return size; }

    void Push(const T & push_value);
    const T & Peek() const {
        try {
            return head->value;
        } catch (const std::exception & e) {
        }
    }

    void Pop();

    void Traverse(std::function<void(const T &)> func);

    void Show() {
        Traverse([](const T & val) { std::cout << val << ' '; });
    }
};

QUEUE_NAMESPACE_END

#endif // !_MYQUEUE_HPP_

template <typename T> void myqueue::Queue<T>::Push(const T & push_value) {
    if (Empty()) {
        head = tail = std::make_shared<Node<T>>(push_value);
        size++;
        return;
    }

    tail->next = std::make_shared<Node<T>>(push_value);
    tail = tail->next;
    size++;

    return;
}

template <typename T> void myqueue::Queue<T>::Pop() {
    if (Empty())
        return;

    head = head->next;
    size--;

    return;
}

template <typename T>
void myqueue::Queue<T>::Traverse(std::function<void(const T &)> func) {
    for (std::shared_ptr<Node<T>> current = head; current;
         current = current->next)
        func(current->value);

    return;
}
