#include<iostream>
#include<cstdlib>
#include<ctime>
#include"binarytree.hpp"

void print(int n);

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;
    MyBinaryTree<int> mbt;
    int num;
    int remove_number;

    std::cout << "Input:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        mbt.insert(num);
    }
    std::cout << '\n';
    std::cout << "Size: " << mbt.size() << '\n';
    mbt.traverse(print, mbt.GetRootNode());
    std::cout << '\n';

    std::cout << "Enter the number you want to remove: ";
    while (std::cin >> remove_number)
    {
        mbt.remove(remove_number);
        std::cout << "After remove():\n";
        std::cout << "Size: " << mbt.size() << '\n';
        mbt.traverse(print, mbt.GetRootNode());
        std::cout << '\n';
        std::cout << "Enter the next number: ";
    }

    return 0;
}

void print(int n)
{
    std::cout << n << ' ';
}