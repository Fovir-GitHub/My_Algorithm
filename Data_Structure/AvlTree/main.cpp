#include<iostream>
#include<cstdlib>
#include<ctime>
#include"avltree.hpp"

void show(int num);

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;
    int num = 0;
    AvlTree<int> avl;
    int remove_number = 0;

    std::cout << "Input:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        avl.insert(num);
    }
    std::cout << '\n';

    avl.traverse(show);
    std::cout << '\n';

    std::cout << "Enter remove number: ";
    while (std::cin >> remove_number)
    {
        avl.remove(remove_number);
        avl.traverse(show);
        std::cout << '\n';
    }

    return 0;
}

void show(int num)
{
    std::cout << num << ' ';
}