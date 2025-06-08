#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> findTwoSum(std::vector<int> & v, int target);

int main(void) {
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;
    std::vector<int> numbers;
    int target = 0;

    for (int i = 0; i < N; i++)
        numbers.push_back(std::rand() % LIMIT);

    std::sort(numbers.begin(), numbers.end());
    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << '\n';

    std::cout << "Enter the sum: ";
    while (std::cin >> target) {
        std::vector<int> result = findTwoSum(numbers, target);
        std::cout << "Result: ";
        for (auto x : result)
            std::cout << x << ' ';
        std::cout << "\nEntere the next sum: ";
    }
}

std::vector<int> findTwoSum(std::vector<int> & v, int target) {
    std::unordered_map<int, int> records;
    size_t size = v.size();

    for (int i = 0; i < size; i++) {
        if (records.find(target - v[i]) != records.end())
            return {records[target - v[i]], i};

        records.emplace(v[i], i);
    }

    return {};
}