#include "myqueue.hpp"
#include <iostream>
#include <queue>

int main(void) {
    myqueue::Queue<int> q;

    q.Push(1);
    q.Push(2);
    q.Push(3);

    q.Show();

    std::cout << q.Peek() << '\n';

    while (!q.Empty()) {
        std::cout << q.Peek() << '\n';
        q.Pop();
    }

    q.Pop();
    q.Pop();
    return 0;
}