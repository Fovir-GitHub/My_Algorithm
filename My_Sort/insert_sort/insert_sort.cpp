#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<ctime>

template<typename T>
void insertSort(std::vector<T> & v);

int main(void)
{
    const int VEC_SIZE = 10;

    std::srand(std::time(0));
    std::vector<int> v(VEC_SIZE);

    std::generate(v.begin(), v.end(), std::rand);
    insertSort(v);

    for (auto x : v)
        std::cout << x << " ";

    return 0;
}

template<typename T>
void insertSort(std::vector<T> & v)
{
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        T current = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > current)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = current;
    }

    return;
}