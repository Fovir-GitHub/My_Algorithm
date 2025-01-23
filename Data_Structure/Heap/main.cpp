#include "myheap.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;

    int num = 0;
    MyHeap<int> mh;

    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        mh.push(num);
    }

    std::cout << '\n';

    while (!mh.empty())
    {
        std::cout << mh.peek() << ' ';
        mh.pop();
    }

    return 0;
}