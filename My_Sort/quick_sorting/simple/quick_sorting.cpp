#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int partition(std::vector<int> & numbers, int left, int right);
void quickSort(std::vector<int> & numbers, int left, int right);

int main(void)
{
    std::srand(std::time(0));

    const int VECTOR_SIZE = 10, LIMIT = 20;

    std::vector<int> numbers(VECTOR_SIZE);

    std::generate(numbers.begin(), numbers.end(),
                  []() { return std::rand() % LIMIT; });
    quickSort(numbers, 0, numbers.size() - 1);

    for (auto x : numbers) std::cout << x << ' ';

    return 0;
}

int partition(std::vector<int> & numbers, int left, int right)
{
    int i = left, j = right;

    while (i < j)
    {
        while (i < j && numbers[j] >= numbers[left]) j--;
        while (i < j && numbers[i] <= numbers[left]) i++;

        std::swap(numbers[i], numbers[j]);
    }

    std::swap(numbers[i], numbers[left]);

    return i;
}

void quickSort(std::vector<int> & numbers, int left, int right)
{
    if (left >= right)
        return;

    int middle = partition(numbers, left, right);
    quickSort(numbers, left, middle - 1);
    quickSort(numbers, middle + 1, right);

    return;
}
