#include <iostream>
#include <string>
#include <vector>

void output(const std::vector<int> & v);

int main(void) {
    const int BASE = 2;

    std::string first, second;
    std::vector<int> a, b;

    std::cin >> first >> second;

    for (auto x : first)
        a.push_back(x - '0');
    for (auto x : second)
        b.push_back(x - '0');

    int n = a.size();
    std::vector<int> c(n + 1);
    int next = 0;
    std::fill(c.begin(), c.end(), 0);

    for (int i = n; i >= 1; i--) {
        c[i] = (a[i - 1] + b[i - 1] + next) % BASE;
        next = (a[i - 1] + b[i - 1] + next) / BASE;
    }
    c[0] = next;

    output(c);

    return 0;
}

void output(const std::vector<int> & v) {
    for (auto x : v)
        std::cout << x;
    std::cout << '\n';

    return;
}
