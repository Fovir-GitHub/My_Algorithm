#include <iostream>
#include <string>
#include <vector>

class UnlockPasscode {
private:
    enum { LIMIT = 3 };

    std::vector<std::string> targets;
    std::vector<int> trying;
    int number_of_targets = 0;

    std::string Vector2String(const std::vector<int> & source);

public:
    UnlockPasscode() : trying(std::vector<int>(LIMIT, 0)) {}

    ~UnlockPasscode() {}

    void GetTarget();

    void Solve(int pos);
};

std::string UnlockPasscode::Vector2String(const std::vector<int> & source) {
    std::string result("");

    for (const int & it : source)
        result.append(std::to_string(it));

    return result;
}

void UnlockPasscode::GetTarget() {
    std::vector<int> temp(LIMIT, 0);

    std::cout << "Number of passcodes: ";
    std::cin >> number_of_targets;

    for (int i = 1; i <= number_of_targets; i++) {
        std::cout << "Passcode " << i << ": ";
        for (int & num : temp)
            std::cin >> num;
        targets.push_back(Vector2String(temp));
    }

    return;
}

void UnlockPasscode::Solve(int pos) {
    if (number_of_targets <= 0)
        return;

    if (pos == LIMIT) {
        std::cout << "Trying: ";
        for (const int & it : trying)
            std::cout << it << ' ';
        std::cout << '\n';

        std::string temp = Vector2String(trying);
        for (int i = 0; i < targets.size(); i++)
            if (temp == targets[i]) {
                std::cout << "Passcode " << i + 1 << " Unlocked\n";
                number_of_targets--;
                break;
            }

        return;
    }

    for (int i = 0; i < LIMIT; i++) {
        trying[pos] = i;
        Solve(pos + 1);
    }

    return;
}

int main(void) {
    UnlockPasscode up;

    up.GetTarget();
    up.Solve(0);
}
