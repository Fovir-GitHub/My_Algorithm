#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int findNumber(std::vector<int> & v, int target);

int main(void) {
    std::srand(std::time(0));

    const int LIMIT = 20;

    int number_counter = 0;
    int find_number = 0;
    std::vector<int> numbers;

    std::cout << "How many numbers do you want: ";
    std::cin >> number_counter;

    for (int i = 0; i < number_counter; i++)
        numbers.push_back(std::rand() % LIMIT);

    std::sort(numbers.begin(), numbers.end());
    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << '\n';

    std::cout << "Enter the number you want to find: ";
    while (std::cin >> find_number)
        std::cout << findNumber(numbers, find_number) << '\n'
                  << "Enter the next number you want to find: ";

    return 0;
}

int findNumber(std::vector<int> & v, int target) {
    int left = 0, right = v.size() - 1, middle = 0;

    while (left <= right) {
        middle = left + (right - left) / 2;
        if (v[middle] == target)
            return middle;

        if (v[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}
