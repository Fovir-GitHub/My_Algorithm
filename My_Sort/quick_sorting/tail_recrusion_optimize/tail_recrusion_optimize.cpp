#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>

int medianThreeOptimizeForTailRecrusionOptimize(std::vector<int> & numbers, int left, int middle, int right);
int partitionMedianThreeOptimizeForTailRecrusionOptimize(std::vector<int> & numbers, int left, int right);
void quickSortTailRecrusionOptimize(std::vector<int> & numbers, int left, int right);

int main(void)
{
    std::srand(std::time(0));

    const int VECTOR_SIZE = 10, LIMIT = 20;
    std::vector<int> numbers(VECTOR_SIZE);

    std::generate(numbers.begin(), numbers.end(),
        []() {return std::rand() % LIMIT; });
    std::cout << "Original data:\n";
    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << "\nAfter sorting:\n";
    quickSortTailRecrusionOptimize(numbers, 0, numbers.size() - 1);
    for (auto x : numbers)
        std::cout << x << ' ';

    return 0;
}

int medianThreeOptimizeForTailRecrusionOptimize(std::vector<int> & numbers, int left, int middle, int right)
{
    int l = numbers[left], m = numbers[middle], r = numbers[right];
    if ((l <= m && m <= r) || (r <= m && m <= l))
        return middle;
    if ((m <= l && l <= r) || (r <= l && l <= m))
        return left;

    return right;
}

int partitionMedianThreeOptimizeForTailRecrusionOptimize(std::vector<int> & numbers, int left, int right)
{
    int middle = medianThreeOptimizeForTailRecrusionOptimize(numbers, left, (left + right) / 2, right);
    std::swap(numbers[middle], numbers[left]);

    int i = left, j = right;
    while (i < j)
    {
        while (i < j && numbers[j] >= numbers[left])
            j--;
        while (i < j && numbers[i] <= numbers[left])
            i++;
        std::swap(numbers[i], numbers[j]);
    }
    std::swap(numbers[i], numbers[left]);

    return i;
}

void quickSortTailRecrusionOptimize(std::vector<int> & numbers, int left, int right)
{
    while (left < right)
    {
        int middle =
            partitionMedianThreeOptimizeForTailRecrusionOptimize(numbers, left, right);

        if (middle - left < right - middle)
        {
            quickSortTailRecrusionOptimize(numbers, left, middle - 1);
            left = middle + 1;
        }
        else
        {
            quickSortTailRecrusionOptimize(numbers, middle + 1, right);
            right = middle - 1;
        }
    }

    return;
}
