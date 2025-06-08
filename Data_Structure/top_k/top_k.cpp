#include <iostream>
#include <queue>
#include <vector>

std::priority_queue<int, std::vector<int>, std::greater<int>>
topkHeap(std::vector<int> & nums, int k);

int main(void) {
    int n, k;

    std::cin >> n >> k;
    std::vector<int> a(n);

    for (auto & x : a)
        std::cin >> x;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq =
        topkHeap(a, k);
    for (; !pq.empty(); pq.pop())
        std::cout << pq.top() << ' ';

    return 0;
}

std::priority_queue<int, std::vector<int>, std::greater<int>>
topkHeap(std::vector<int> & nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

    for (int i = 0; i < k; i++)
        heap.push(nums[i]);

    for (int i = k; i < nums.size(); i++)
        if (nums[i] > heap.top()) {
            heap.pop();
            heap.push(nums[i]);
        }

    return heap;
}
