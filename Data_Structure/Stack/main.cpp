#include "mystack.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(0));

    const int    N = 10, LIMIT = 20;
    MyStack<int> st;

    for (int i = 0; i < N; i++)
    {
        int num = rand() % LIMIT;
        std::cout << num << ' ';
        st.push(num);
    }
    std::cout << '\n';
    std::cout << "Size: " << st.size() << '\n';
    std::cout << "peek(): " << st.peek() << '\n';
    std::cout << "After pop(): " << '\n';
    st.pop();
    std::cout << "Size: " << st.size() << '\n'
              << "peek(): " << st.peek() << '\n';

    while (!st.empty()) st.pop();

    std::cout << "Size: " << st.size() << '\n'
              << "peek(): " << st.peek() << '\n';

    std::cout << (st.pop() ? "success" : "fail") << '\n';

    return 0;
}