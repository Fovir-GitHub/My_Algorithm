#include <iostream>
#include <vector>

using std::vector;

class SubsetSum {
private:
    std::vector<int> choices;

    void Backtracking(std::vector<int> & state, int & target, int start,
                      int current_sum, std::vector<std::vector<int>> & result);

public:
    SubsetSum(const std::vector<int> & ch);

    vector<std::vector<int>> Solve(int target) {
        std::vector<int> state;
        std::vector<std::vector<int>> result;
        Backtracking(state, target, 0, 0, result);

        return result;
    }
};

void SubsetSum::Backtracking(std::vector<int> & state, int & target, int start,
                             int current_sum,
                             std::vector<std::vector<int>> & result) {
    if (current_sum == target) {
        result.push_back(state);
        return;
    }

    for (int i = start; i < choices.size(); i++) {
        int choice = choices[i];

        if (current_sum + choice > target) {
            continue;
        }

        state.push_back(choice);
        Backtracking(state, target, i, current_sum + choice, result);
        state.pop_back();
    }
}

SubsetSum::SubsetSum(const std::vector<int> & ch) : choices(ch) {}

int main() {
    std::vector<int> choices = {3, 4, 5};
    int target = 9;
    SubsetSum ss(choices);

    for (const auto & row : ss.Solve(target)) {
        for (const int & num : row) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

