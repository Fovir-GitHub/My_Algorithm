#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

template <typename T> void insertSort(std::vector<T> & v);

int main(void) {
    const int VEC_SIZE = 10;

    std::srand(std::time(0));
    std::vector<int> v(VEC_SIZE);

    std::generate(v.begin(), v.end(), []() { return std::rand() % 20; });
    insertSort(v);

    for (auto x : v)
        std::cout << x << " ";

    return 0;
}

template <typename T> void insertSort(std::vector<T> & v) {
    int n = v.size();

    for (int i = 1; i < n; i++) {
        T current = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > current) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = current;
    }

    return;
}
