#include<iostream>
#include<vector>

void choose_sort(std::vector<int> & v);

int main(void)
{
    std::vector<int> a;
    int temp;

    while (std::cin >> temp)
        a.push_back(temp);

    choose_sort(a);
    for (auto x : a)
        std::cout << x << ' ';

    return 0;
}

void choose_sort(std::vector<int> & v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        int min_n = v[i];
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
            if (min_n > v[j])
            {
                min_pos = j;
                min_n = v[j];
            }

        std::swap(v[i], v[min_pos]);
    }

    return;
}
