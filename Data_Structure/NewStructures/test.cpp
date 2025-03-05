#include "newstack.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(0));

    const int     N = 10, LIMIT = 20;
    int           num;
    NewStack<int> nst;

    std::cout << "Input:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        nst.push(num);
    }
    std::cout << '\n';

    while (!nst.empty())
    {
        std::cout << nst.peek() << ' ';
        nst.pop();
    }

    return 0;
}