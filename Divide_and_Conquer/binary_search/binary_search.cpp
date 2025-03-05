#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int dfs(std::vector<int> & numbers, int target, int left, int right);
int binarySearch(std::vector<int> & numbers, int target);

int main(void)
{
    const int        VECTOR_SIZE = 20;
    std::vector<int> numbers(VECTOR_SIZE);
    int              find_number = 0;

    std::random_device              rd;
    std::mt19937                    gen(rd());
    std::uniform_int_distribution<> uid(0, 100);
    std::generate(numbers.begin(), numbers.end(), [&]() { return uid(gen); });
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Original data:\n";
    for (auto x : numbers) std::cout << x << ' ';
    std::cout << '\n';

    std::cout << "Enter the number you want to find: ";
    while (std::cin >> find_number)
        std::cout << "Position: " << binarySearch(numbers, find_number) << '\n'
                  << "Enter the next number you want to find: ";

    return 0;
}

int dfs(std::vector<int> & numbers, int target, int left, int right)
{
    if (left > right)
        return -1;

    int middle = left + (right - left) / 2;

    if (numbers[middle] == target)
        return middle;

    if (numbers[middle] < target)
        return dfs(numbers, target, middle + 1, right);
    else
        return dfs(numbers, target, left, middle - 1);
}

int binarySearch(std::vector<int> & numbers, int target)
{
    return dfs(numbers, target, 0, numbers.size() - 1);
}