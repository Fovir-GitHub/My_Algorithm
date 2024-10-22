#include<iostream>
#include<cstdlib>
#include<ctime>
#include"mydeque.hpp"

int main(void)
{
    std::srand(std::time(0));

    const int N = 5, LIMIT = 20;
    int num;
    MyDeque<int> mdeq;

    std::cout << "push_front():\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        mdeq.push_front(num);
    }
    std::cout << '\n'
        << "push_back():\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        mdeq.push_back(num);
    }
    std::cout << '\n';

    std::cout << "peek_front(): " << mdeq.peek_front() << '\n'
        << "peek_back(): " << mdeq.peek_back() << '\n';

    std::cout << "From front:\n";
    for (int i = 0; i < N; i++, mdeq.pop_front())
        std::cout << mdeq.peek_front() << ' ';
    std::cout << '\n';

    std::cout << "From back:\n";
    for (int i = 0; i < N; i++, mdeq.pop_back())
        std::cout << mdeq.peek_back() << ' ';
    std::cout << '\n';

    std::cout << "Size: " << mdeq.size() << '\n';

    return 0;
}