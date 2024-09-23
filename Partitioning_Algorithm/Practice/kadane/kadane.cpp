#include<iostream>
#include<vector>
#include<algorithm>

int main(void)
{
    std::vector<int> temp_vector, v;
    int temp;
    int max_ending_here, max_so_far;

    while (std::cin >> temp)
        temp_vector.push_back(temp);

    v.push_back(temp_vector[0]);
    for (size_t i = 1; i < temp_vector.size(); i++)
        v.push_back(temp_vector[i] - temp_vector[i - 1]);

    max_ending_here = max_so_far = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        max_ending_here = std::max(v[i], max_ending_here + v[i]);
        max_so_far = std::max(max_ending_here, max_so_far);
    }

    std::cout << "Max sum: " << max_so_far << '\n';

    return 0;
}