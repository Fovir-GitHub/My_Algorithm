#include<iostream>
#include<random>
#include<algorithm>
#include<vector>

int digit(int number, int exp);
void countDigitSorting(std::vector<int> & numbers, int exp);
void radixSort(std::vector<int> & numbers);

int main(void)
{
    const int VECTOR_SIZE = 20;

    std::vector<int> numbers(VECTOR_SIZE);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uid((int) 1E7, (int) 1E8);

    std::generate(numbers.begin(), numbers.end(),
        [&]() {return uid(gen); });
    std::cout << "Original data:\n";
    for (auto x : numbers)
        std::cout << x << '\n';
    std::cout << "\nAfter sort:\n";
    radixSort(numbers);
    for (auto x : numbers)
        std::cout << x << '\n';

    return 0;
}

int digit(int number, int exp)
{
    return (number / exp) % 10;
}

void countDigitSorting(std::vector<int> & numbers, int exp)
{
    std::vector<int> counter(10, 0);
    int n = numbers.size();

    for (int i = 0; i < n; i++)
        counter[digit(numbers[i], exp)]++;

    for (int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];

    std::vector<int> result(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int d = digit(numbers[i], exp);
        int j = counter[d] - 1;
        result[j] = numbers[i];
        counter[d]--;
    }
    numbers = result;

    return;
}

void radixSort(std::vector<int> & numbers)
{
    int max_value = *std::max_element(numbers.begin(), numbers.end());

    for (int exp = 1; exp <= max_value; exp *= 10)
        countDigitSorting(numbers, exp);

    return;
}
