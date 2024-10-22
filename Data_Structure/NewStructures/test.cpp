#include<iostream>
#include<cstdlib>
#include<ctime>
#include"newqueue.hpp"

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;
    int num;
    NewQueue<int> nque;

    std::cout << "Input:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        nque.push(num);
    }
    std::cout << '\n';

    while (!nque.empty())
    {
        std::cout << nque.peek() << ' ';
        nque.pop();
    }

    return 0;
}