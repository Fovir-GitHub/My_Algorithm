#include "myqueue.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;

    MyQueue<int> mq;

    std::cout << "Size: " << mq.size() << '\n';

    for (int i = 0; i < N; i++)
    {
        int num = std::rand() % LIMIT;
        std::cout << num << ' ';
        mq.push(num);
    }
    std::cout << '\n';

    std::cout << "Size: " << mq.size() << '\n'
              << "peek(): " << mq.peek() << '\n';

    std::cout << "After pop():\n";
    mq.pop();
    std::cout << "Size: " << mq.size() << '\n'
              << "peek(): " << mq.peek() << '\n';

    while (!mq.empty())
    {
        std::cout << mq.peek() << ' ';
        mq.pop();
    }
    std::cout << '\n';

    std::cout << (mq.pop() ? "success" : "fail") << '\n';

    return 0;
}