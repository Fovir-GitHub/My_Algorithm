#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>

int generateData() { return std::rand() % 20; }

int main(void)
{
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

    int n = v.size();
    for (size_t i = 1; i < n; i++)
        for (size_t j = 1; j < n; j++)
            if (v[j] < v[j - 1])
                std::swap(v[j], v[j - 1]);

    for (auto x : v)
        std::cout << x << ' ';

    return 0;
}