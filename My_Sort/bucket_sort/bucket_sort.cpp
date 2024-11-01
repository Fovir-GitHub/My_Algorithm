#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

void bucketSort(std::vector<double> & numbers);

int main(void)
{
    const int VECTOR_SIZE = 10;

    std::vector<double> numbers(VECTOR_SIZE);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    std::generate(numbers.begin(), numbers.end(),
        [&]() {return (double) dis(gen); });

    std::cout << "Original data:\n";
    for (auto x : numbers)
        std::cout << x << ' ';
    std::cout << "\nAfter sort:\n";
    bucketSort(numbers);
    for (auto x : numbers)
        std::cout << x << ' ';

    return 0;
}

void bucketSort(std::vector<double> & numbers)
{
    int k = numbers.size() / 2;
    std::vector<std::vector<double>> buckets(k);

    for (double num : numbers)
        buckets[num * k].push_back(num);

    for (auto & bucket : buckets)
        std::sort(bucket.begin(), bucket.end());

    int i = 0;
    for (auto & bucket : buckets)
        for (auto num : bucket)
            numbers[i++] = num;

    return;
}
