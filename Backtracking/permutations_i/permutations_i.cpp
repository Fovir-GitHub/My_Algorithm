#include <iostream>
#include <vector>

class Permutation {
private:
    std::vector<bool> selected;

    void Backtracking(std::vector<int> & state,
                      std::vector<std::vector<int>> & result) {
        if (state.size() == selected.size()) {
            result.push_back(state);
            return;
        }

        for (int i = 0; i < selected.size(); i++) {
            if (!selected[i]) {
                selected[i] = true;
                state.push_back(i);
                Backtracking(state, result);
                state.pop_back();
                selected[i] = false;
            }
        }
    }

public:
    Permutation(int n) : selected(n, false) {}
    ~Permutation() {}

    std::vector<std::vector<int>> Solve() {
        std::vector<std::vector<int>> result;
        std::vector<int> state;

        Backtracking(state, result);

        return result;
    }
};

int main() {
    int n;

    while (std::cin >> n) {
        Permutation permutation(n);

        for (const auto & row : permutation.Solve()) {
            for (const auto & num : row) {
                std::cout << num << ' ';
            }
            std::cout << '\n';
        }

        std::cout << "\n\n";
    }

    return 0;
}

