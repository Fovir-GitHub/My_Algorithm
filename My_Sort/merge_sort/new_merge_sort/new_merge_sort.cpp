#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void mergeSort(std::vector<int> & v, int left, int right);
void merge(std::vector<int> & v, int left, int middle, int right);

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
    mergeSort(numbers, 0, numbers.size() - 1);
    for (auto x : numbers) std::cout << x << ' ';

    return 0;
}

void mergeSort(std::vector<int> & v, int left, int right)
{
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;
    mergeSort(v, left, middle);
    mergeSort(v, middle + 1, right);
    merge(v, left, middle, right);

    return;
}

void merge(std::vector<int> & v, int left, int middle, int right)
{
    std::vector<int> temp(right - left + 1);

    int i = left, j = middle + 1, k = 0;

    while (i <= middle && j <= right)
    {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while (i <= middle) temp[k++] = v[i++];
    while (j <= right) temp[k++] = v[j++];

    for (k = 0; k < temp.size(); k++) v[left + k] = temp[k];

    return;
}
