#include <iostream>

int Solution(int n);

int main() {
    int stairs = 0;

    while (std::cin >> stairs) {
        std::cout << Solution(stairs) << '\n';
    }
}

int Solution(int n) {
    if (n < 3) {
        return n;
    }

    int a = 1, b = 2;
    for (int i = 0; i <= n; i++) {
        int temp = b;
        b += a;
        a = temp;
    }

    return b;
}

