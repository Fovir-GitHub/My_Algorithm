#include <iostream>
#include <unordered_set>
#include <vector>

class PermutationsII {
private:
    std::vector<int> choice;
    std::vector<bool> selected;

    void Backtracking(std::vector<int> & state,
                      std::vector<std::vector<int>> & result);

public:
    PermutationsII(const std::vector<int> & c);

    ~PermutationsII() {}

    std::vector<std::vector<int>> Solve();
};

std::vector<std::vector<int>> PermutationsII::Solve() {
    std::vector<int> state;
    std::vector<std::vector<int>> result;

    Backtracking(state, result);

    return result;
}

void PermutationsII::Backtracking(std::vector<int> & state,
                                  std::vector<std::vector<int>> & result) {
    if (state.size() == choice.size()) {
        result.push_back(state);
        return;
    }

    std::unordered_set<int> duplicated;
    for (int i = 0; i < choice.size(); i++) {
        int temp = choice[i];

        if (!selected[temp] && !duplicated.count(temp)) {
            selected[i] = true;
            duplicated.emplace(temp);
            state.push_back(temp);
            Backtracking(state, result);
            state.pop_back();
            selected[i] = false;
        }
    }
}

PermutationsII::PermutationsII(const std::vector<int> & c)
    : choice(c), selected(c.size(), false) {}

int main() {
    std::vector<int> choice = {1, 1, 1, 2};
    PermutationsII pii(choice);

    for (const auto & row : pii.Solve()) {
        for (const auto & num : row) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

