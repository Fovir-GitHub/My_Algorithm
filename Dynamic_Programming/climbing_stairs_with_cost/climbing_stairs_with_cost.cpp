#include <iostream>
#include <vector>

int minCost(const std::vector<int> & costs);

int main() {
    std::vector<int> costs = {0, 100, 2, 3, 6, 1, 10, 1};
    std::cout << minCost(costs);

    return 0;
}

int minCost(const std::vector<int> & costs) {
    int n = costs.size() - 1;

    if (n < 3) {
        return costs[n];
    }

    int a = costs[1], b = costs[2];
    for (int i = 3; i <= n; i++) {
        int temp = b;
        b = std::min(a, temp) + costs[i];
        a = temp;
    }

    return b;
}

