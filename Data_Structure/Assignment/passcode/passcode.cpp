#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

static const int LIMIT = 3;

class UnlockPasscode {
private:
    std::vector<int> state;

    void MakeState(int pos) {
        if (pos == LIMIT) {
            return;
        }

        state[pos] = std::rand() % LIMIT;
        MakeState(pos + 1);
    }

    void Try(const std::vector<int> & target) {
        do {
            MakeState(0);
            std::cout << "Trying: ";
            for (const int & num : state) {
                std::cout << num << " ";
            }
            std::cout << '\n';
        } while (state != target);
    }

public:
    UnlockPasscode() : state(LIMIT, 0) { std::srand(std::time(nullptr)); }

    void Solution(const std::vector<std::vector<int>> & targets) {
        for (int i = 0; i < targets.size(); i++) {
            Try(targets[i]);
            std::cout << "Passcode " << i + 1 << " Unlocked\n";
        }
    }
};

int main() {
    int n = 0;

    std::cout << "Number of passcodes: ";
    std::cin >> n;

    std::vector<std::vector<int>> targets(n, std::vector<int>(LIMIT, 0));
    for (int i = 0; i < n; i++) {
        std::cout << "Passcode " << i + 1 << ": ";
        for (int j = 0; j < LIMIT; j++) {
            std::cin >> targets[i][j];
        }
    }

    UnlockPasscode up;
    up.Solution(targets);

    return 0;
}
