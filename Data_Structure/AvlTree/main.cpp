#include "avltree.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void show(int number);

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;

    int          num           = 0;
    int          remove_number = 0;
    int          find_number   = 0;
    AvlTree<int> avl;

    std::cout << "Input:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        avl.insert(num);
    }
    std::cout << '\n';

    avl.traverse(show);
    std::cout << '\n';

    // while (std::cin >> remove_number)
    // {
    //     avl.remove(remove_number);
    //     avl.traverse(show);
    //     std::cout << '\n';
    // }

    while (std::cin >> find_number)
        std::cout << (avl.find(find_number) ? "Find" : "Not found") << '\n';

    return 0;
}

void show(int number)
{
    std::cout << number << ' ';
}