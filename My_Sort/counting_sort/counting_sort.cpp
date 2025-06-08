#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void countingSortNative(std::vector<int> & numbers);
void countingSort(std::vector<int> & numbers);

int main(void) {
    const int VECTOR_SIZE = 10;
    std::vector<int> numbers(VECTOR_SIZE);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 20);

    std::generate(numbers.begin(), numbers.end(), [&]() { return dis(gen); });
    std::cout << "Original data:\n";
    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << "\nAfter sort:\n";
    countingSortNative(numbers);
    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << '\n';

    std::cout << "New generated data:\n";
    std::generate(numbers.begin(), numbers.end(), [&]() { return dis(gen); });
    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << "\nAfter sort:\n";
    countingSort(numbers);
    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << '\n';

    return 0;
}

void countingSortNative(std::vector<int> & numbers) {
    int max_value = 0;
    for (auto x : numbers)
        max_value = std::max(max_value, x);

    std::vector<int> counter(max_value + 1, 0);
    for (auto x : numbers)
        counter[x]++;

    int position = 0;
    for (int i = 0; i < counter.size(); i++)
        for (int j = 0; j < counter[i]; j++)
            numbers[position++] = i;

    return;
}

void countingSort(std::vector<int> & numbers) {
    int max_value = 0;
    for (auto x : numbers)
        max_value = std::max(max_value, x);

    std::vector<int> counter(max_value + 1, 0);
    for (auto x : numbers)
        counter[x]++;

    for (int i = 0; i < max_value; i++)
        counter[i + 1] += counter[i];

    int n = numbers.size();
    std::vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        int num = numbers[i];
        result[counter[num] - 1] = num;
        counter[num]--;
    }
    numbers = result;

    return;
}
