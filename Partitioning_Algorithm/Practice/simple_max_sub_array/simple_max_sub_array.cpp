#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>

int main(void)
{
    std::freopen("./test.in", "r", stdin);

    std::vector<int> temp_vector, v, sums;
    int temp;

    while (std::cin >> temp) temp_vector.push_back(temp);

    v.push_back(temp_vector[0]);
    for (size_t i = 1; i < temp_vector.size(); i++)
        v.push_back(temp_vector[i] - temp_vector[i - 1]);

    for (size_t i = 0; i < v.size(); i++)
    {
        sums.push_back(v[i]);
        for (size_t j = i + 1; j < v.size(); j++)
            sums.push_back(sums.back() + v[j]);
    }

    int max_sum = 0;
    for (auto x : sums) max_sum = std::max(max_sum, x);

    std::cout << "Max sum: " << max_sum << '\n';

    return 0;
}