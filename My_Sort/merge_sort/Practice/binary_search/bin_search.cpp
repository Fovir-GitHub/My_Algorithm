#include <iostream>
#include <iterator>
#include <vector>

typedef std::vector<int>::iterator Iter;

bool haveNumber(const std::vector<int> & v, Iter left, Iter right,
                const int & target);

int main(void)
{
    const int VECTOR_SIZE = 1000;

    int number_to_find;
    std::vector<int> numbers(VECTOR_SIZE);

    for (int i = 0; i < VECTOR_SIZE; i++) numbers[i] = i * i;

    std::cout << "Enter the number you want to find: ";

    while (std::cin >> number_to_find)
        std::cout << (haveNumber(numbers, numbers.begin(), numbers.end(),
                                 number_to_find)
                          ? "Have"
                          : "Don't have")
                  << " " << number_to_find << '\n'
                  << "Enter the next number you want to find: ";

    std::cout << "Done." << '\n';

    return 0;
}

bool haveNumber(const std::vector<int> & v, Iter left, Iter right,
                const int & target)
{
    int distance;
    if ((distance = std::distance(left, right)) <= 1)
        return false;

    Iter middle = left;
    std::advance(middle, distance / 2);

    if (*middle == target)
        return true;
    else if (*middle < target)
        return haveNumber(v, middle, right, target);
    else
        return haveNumber(v, left, middle, target);
}
