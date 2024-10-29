#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>

int binaryInsert(std::vector<int> & v, int target);

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;

    std::vector<int> numbers;
    int insert_number = 0;

    for (int i = 0; i < N; i++)
        numbers.push_back(std::rand() % LIMIT);

    std::sort(numbers.begin(), numbers.end());
    std::for_each(numbers.begin(), numbers.end(),
        [&](int & num) {std::cout << num << ' '; });
    std::cout << '\n';

    std::cout << "Please enter the number you want to insert: ";
    while (std::cin >> insert_number)
        std::cout << "Insert position: "
        << binaryInsert(numbers, insert_number) << '\n'
        << "Please enter the next number you want to insert: ";

    return 0;
}

int binaryInsert(std::vector<int> & v, int target)
{
    int left = 0, right = v.size() - 1, middle = 0;

    while (left <= right)
    {
        middle = left + (right - left) / 2;

        if (v[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return left;
}
