#include<iostream>
#include<vector>
#include<iterator>
#include<cstring>

int main(void)
{
    std::freopen("./test.in", "r", stdin);

    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    int * original_array = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> original_array[i];

    int * differ_array = new int[n];

    differ_array[0] = original_array[0];
    for (int i = 1; i < n; i++)
        differ_array[i] = original_array[i] - original_array[i - 1];

    int ** record = new int * [n];
    for (int i = 0; i < n; i++)
        record[i] = new int[n];

    for (int i = 0; i < n; i++)
        std::memset(record[i], 0, sizeof(int) * n);
    for (int i = 0; i < n; i++)
        record[i][0] = differ_array[i];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            record[i][j] = record[i][j - 1] + differ_array[j];

    int max_sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            max_sum = std::max(max_sum, record[i][j]);

    std::cout << "Max sum: " << max_sum << '\n';

    return 0;
}