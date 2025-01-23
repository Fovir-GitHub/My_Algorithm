#include "linklist.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void show(int num);
void show(LinkList<int> & ll);

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;
    LinkList<int> link_list;

    for (int i = 0; i < N; i++) link_list.push((std::rand() % LIMIT));

    std::cout << "Original:\n";
    show(link_list);

    std::cout << "After insert():\n";
    link_list.insert(100, 1);
    show(link_list);

    std::cout << "After remove():\n";
    link_list.remove(1);
    show(link_list);

    std::cout << "After second remove():\n";
    link_list.remove(100);
    link_list.remove(-1);
    show(link_list);

    int find_number;
    std::cout << "Please enter the find_number: ";
    std::cin >> find_number;
    std::cout << (link_list.find(find_number) ? "Find" : "Don't find") << " "
              << find_number << '\n';

    return 0;
}

void show(int num)
{
    std::cout << num << ' ';
    return;
}

void show(LinkList<int> & ll)
{
    std::cout << "size: " << ll.size() << '\n';
    ll.access(show);
    std::cout << '\n';

    return;
}
