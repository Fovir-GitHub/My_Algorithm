#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int generateData() { return std::rand() % 20; }
void bubbleSort(std::vector<int> & numbers);

int main(void) {
    const int VECTOR_SIZE = 10;
    std::srand(std::time(0));

    std::vector<int> v(VECTOR_SIZE);
    int temp;

    std::generate(v.begin(), v.end(), generateData);
    std::cout << "Original data:\n";
    for (auto x : v)
        std::cout << x << ' ';
    std::cout << "\nAfter sorting:\n";
    // while (std::cin >> temp)
    // v.push_back(temp);

    bubbleSort(v);
    for (auto x : v)
        std::cout << x << ' ';

    return 0;
}

void bubbleSort(std::vector<int> & numbers) {
    int n = numbers.size();

    for (int i = n - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j < i; j++)
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
                flag = true;
            }

        if (!flag)
            break;
    }

    return;
}