#include<iostream> 
#include<vector>
#include<cstdlib>
#include<algorithm>

template<typename T>
void anti_insert_sort(std::vector<T> & v);

template<typename T>
void anti_insert_sort(std::vector<T> & v)
{
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        T key = v[i];
    }
}
