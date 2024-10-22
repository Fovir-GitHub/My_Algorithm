#include<iostream>
#include<cstdlib>
#include<ctime>
#include"binarytree.hpp"

void print(int & n);

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;
    MyBinaryTree<int> mbt;
    int num;

    std::cout << "Input:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << (num = std::rand() % LIMIT) << ' ';
        mbt.insert(num);
    }
    std::cout << '\n';
    mbt.traverse(print, mbt.GetRootNode());
    std::cout << '\n';

    return 0;
}

void print(int & n)
{
    std::cout << n << ' ';
}
