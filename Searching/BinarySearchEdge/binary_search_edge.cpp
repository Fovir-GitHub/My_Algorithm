#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int binarySearchLeftEdge(std::vector<int> & v, int target);
int binarySearchRightEdge(std::vector<int> & v, int target);

int binaryInsert(std::vector<int> & v, int target);

int binarySearchLeftEdgeElement(std::vector<int> & v, int target);
int binarySearchRightEdgeElement(std::vector<int> & v, int target);

int main(void)
{
    std::srand(std::time(0));

    const int N = 10, LIMIT = 20;

    std::vector<int> numbers;
    int find_edge_number = 0;

    for (int i = 0; i < N; i++) numbers.push_back(std::rand() % LIMIT);

    std::sort(numbers.begin(), numbers.end());
    std::for_each(numbers.begin(), numbers.end(),
                  [&](int & num) { std::cout << num << ' '; });

    std::cout << "\nPlease enter the number you want to find edge: ";
    while (std::cin >> find_edge_number)
        std::cout << "Left edge: "
                  << binarySearchLeftEdge(numbers, find_edge_number) << ' '
                  << "Right edge: "
                  << binarySearchRightEdge(numbers, find_edge_number) << '\n'
                  << "Through find element, left edge: "
                  << binarySearchLeftEdgeElement(numbers, find_edge_number)
                  << ' ' << "right edge: "
                  << binarySearchRightEdgeElement(numbers, find_edge_number)
                  << '\n'
                  << "Please enter the next number you want to find edge: ";

    return 0;
}

int binarySearchLeftEdge(std::vector<int> & v, int target)
{
    int result = binaryInsert(v, target);
    if (result == v.size() || v[result] != target)
        return -1;

    return result;
}

int binarySearchRightEdge(std::vector<int> & v, int target)
{
    int result = binaryInsert(v, target + 1) - 1;
    return (v[result] == target ? result : -1);
}

int binarySearchLeftEdgeElement(std::vector<int> & v, int target)
{
    double new_target = (double) target - 0.5;
    int left = 0, right = v.size() - 1, middle = 0;

    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (v[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    if (left == v.size() || v[left] != target)
        return -1;

    return left;
}

int binarySearchRightEdgeElement(std::vector<int> & v, int target)
{
    double new_target = (double) target + 0.5;
    int left = 0, right = v.size() - 1, middle = 0;

    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (v[middle] <= target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    if (right == v.size() || v[right] != target)
        return -1;

    return right;
}

int binaryInsert(std::vector<int> & v, int target)
{
    int left = 0, right = v.size() - 1, middle = 0;

    while (left <= right)
    {
        middle = left + (right - left) / 2;

        if (v[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return left;
}
