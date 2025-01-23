#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

template <typename T> void anti_insert_sort(std::vector<T> & v);

int generateData()
{
    return std::rand() % 20;
}

int main(void)
{
    const int N = 5;

    std::srand(std::time(0));
    std::vector<int> v(N);

    std::generate(v.begin(), v.end(), generateData);
    anti_insert_sort(v);

    for (auto x : v) std::cout << x << " ";

    return 0;
}

template <typename T> void anti_insert_sort(std::vector<T> & v)
{
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        T current = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < current)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = current;
    }

    return;
}