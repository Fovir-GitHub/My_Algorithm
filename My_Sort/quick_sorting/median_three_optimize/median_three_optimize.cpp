#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int medianThree(std::vector<int> & numbers, int left, int middle, int right);
int partitionMedianThreeOptimize(std::vector<int> & numbers, int left,
                                 int right);
void quickSortMedianThreeOptimize(std::vector<int> & numbers, int left,
                                  int right);

int main(void)
{
    std::srand(std::time(0));

    const int VECTOR_SIZE = 10, LIMIT = 20;

    std::vector<int> numbers(VECTOR_SIZE);
    std::generate(numbers.begin(), numbers.end(),
                  []() { return std::rand() % LIMIT; });
    std::cout << "Original data:\n";
    for (auto x : numbers) std::cout << x << ' ';
    std::cout << "\nAfter sorting:\n";

    quickSortMedianThreeOptimize(numbers, 0, numbers.size() - 1);
    for (auto x : numbers) std::cout << x << ' ';

    return 0;
}

int medianThree(std::vector<int> & numbers, int left, int middle, int right)
{
    int l = numbers[left], m = numbers[middle], r = numbers[right];

    if ((m >= l && m <= r) || (m >= r && m <= l))
        return middle; /* m between l and r */
    if ((l <= r && l >= m) || (l <= m && l >= r))
        return left; /* l between m and r */

    return right;
}

int partitionMedianThreeOptimize(std::vector<int> & numbers, int left,
                                 int right)
{
    int middle = medianThree(numbers, left, (left + right) / 2, right);

    std::swap(numbers[left], numbers[middle]);
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

void quickSortMedianThreeOptimize(std::vector<int> & numbers, int left,
                                  int right)
{
    if (left >= right)
        return;

    int middle = partitionMedianThreeOptimize(numbers, left, right);
    quickSortMedianThreeOptimize(numbers, left, middle - 1);
    quickSortMedianThreeOptimize(numbers, middle + 1, right);

    return;
}