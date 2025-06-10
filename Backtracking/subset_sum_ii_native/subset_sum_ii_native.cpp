#include <iostream>
#include <unordered_set>
#include <vector>

class SubsetSumII {
private:
    std::vector<int> choices;
    int target;

    void Backtracking(std::vector<int> & state, int start, int current_sum,
                      std::vector<std::vector<int>> & result);

public:
    SubsetSumII(const std::vector<int> & ch, int t) : choices(ch), target(t) {}
    ~SubsetSumII() {}

    std::vector<std::vector<int>> Solve();
};

std::vector<std::vector<int>> SubsetSumII::Solve() {
    std::vector<std::vector<int>> result;
    std::vector<int> state;

    Backtracking(state, 0, 0, result);

    return result;
}

void SubsetSumII::Backtracking(std::vector<int> & state, int start,
                               int current_sum,
                               std::vector<std::vector<int>> & result) {
    if (current_sum == target) {
        result.push_back(state);
        return;
    }

    std::unordered_set<int> duplicated;
    for (int i = start; i < choices.size(); i++) {
        int choice = choices[i];
        if (choice + current_sum > target) {
            continue;
        }

        if (!duplicated.count(choice)) {
            duplicated.emplace(choice);
            state.push_back(choice);
            Backtracking(state, i, current_sum + choice, result);
            state.pop_back();
        }
    }
}

int main() {
    std::vector<int> data = {4, 4, 5, 3, 6, 9, 9, 3, 3, 2, 2, 7};
    int target = 9;
    SubsetSumII ssii(data, target);

    for (const auto & row : ssii.Solve()) {
        for (const int & num : row) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

