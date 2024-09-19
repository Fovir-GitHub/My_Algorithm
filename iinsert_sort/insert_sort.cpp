#include<iostream>
#include<vector>

template<typename T>
void insertSort(std::vector<T> & v);

int main(void)
{
    std::vector<int> v;
    int num, n = 5;

    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        v.push_back(num);
    }
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
        int current = v[i];
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
