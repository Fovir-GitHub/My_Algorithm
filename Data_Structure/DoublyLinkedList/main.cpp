#include "myqueue.hpp"
#include <iostream>

template <typename T>
void showQueueStatus(const myqueue::Queue<T> & que)
{
    std::cout << "Size: " << que.Size() << '\n'
              << "Empty: " << que.Empty() << '\n';
}

int main(void)
{
    myqueue::Queue<int> que;
    const int           n = 10;

    showQueueStatus(que);
    for (int i = 0; i < n; i++) que.Push(i);
    showQueueStatus(que);

    while (!que.Empty())
    {
        std::cout << que.Front() << '\n';
        que.Pop();
    }

    showQueueStatus(que);

    que.Pop();

    return 0;
}