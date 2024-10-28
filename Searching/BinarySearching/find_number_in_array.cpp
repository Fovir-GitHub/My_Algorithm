#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>

int findNumber(std::vector<int> & v, int target);

int main(void)
{
    std::srand(std::time(0));

    const int LIMIT = 30;
    int number_counter = 0;
    std::vector<int> numbers;
    int find_number = 0;

    std::cout << "How many numbers do you want: ";
    std::cin >> number_counter;

    while (number_counter--)
        numbers.push_back(std::rand() % LIMIT);

    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << '\n';

    std::cout << "Enter the number you want to find: ";
    while (std::cin >> find_number)
        std::cout << findNumber(numbers, find_number) << '\n'
        << "Enter the next number you want to find: ";

    return 0;
}

int findNumber(std::vector<int> & v, int target)
{
    std::sort(v.begin(), v.end());

    int left = 0, right = v.size() - 1, middle = 0;

    if (target<v[left] || target>v[right])
        return -1;

    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (target == v[middle])
            return middle;

        if (target < v[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
}