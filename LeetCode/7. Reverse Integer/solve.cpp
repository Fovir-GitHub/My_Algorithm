#include <climits>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x) {
            if ((result > INT_MAX / 10) || (result < INT_MIN / 10))
                return 0;

            result = result * 10 + (x % 10);
            x /= 10;
        }

        return result;
    }
};

int main(void) {
    int input = 0;
    Solution sol;

    while (std::cin >> input)
        std::cout << sol.reverse(input) << '\n';

    return 0;
}