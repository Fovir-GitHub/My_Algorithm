#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void siftDown(std::vector<int> & numbers, int n, int i);
void heapSort(std::vector<int> & numbers);

int main(void)
{
    std::srand(std::time(0));

    const int        VECTOR_SIZE = 10, LIMIT = 20;
    std::vector<int> numbers(VECTOR_SIZE);

    std::generate(numbers.begin(), numbers.end(),
                  []() { return std::rand() % LIMIT; });
    std::cout << "Original data:\n";
    for (auto x : numbers) std::cout << x << ' ';
    std::cout << "\nAfter sort:\n";
    heapSort(numbers);
    for (auto x : numbers) std::cout << x << ' ';

    return 0;
}

void siftDown(std::vector<int> & numbers, int n, int i)
{
    while (true)
    {
        int left         = 2 * i + 1;
        int right        = 2 * i + 2;
        int max_position = i;

        if (left < n && numbers[left] > numbers[max_position])
            max_position = left;
        if (right < n && numbers[right] > numbers[max_position])
            max_position = right;
        if (max_position == i)
            break;

        std::swap(numbers[i], numbers[max_position]);
        i = max_position;
    }

    return;
}

void heapSort(std::vector<int> & numbers)
{
    for (int i = numbers.size() / 2 - 1; i >= 0; i--)
        siftDown(numbers, numbers.size(), i);
    for (int i = numbers.size() - 1; i > 0; i--)
    {
        std::swap(numbers[0], numbers[i]);
        siftDown(numbers, i, 0);
    }

    return;
}
