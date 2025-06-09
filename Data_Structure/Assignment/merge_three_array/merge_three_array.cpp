#include <iostream>
#include <vector>

using Array = std::vector<int>;

class MergeThreeArrays {
private:
    Array MergeTwoArrays(const Array & a, const Array & b) {
        Array::const_iterator a_iter = a.begin(), b_iter = b.begin();
        Array result;

        while (a_iter != a.end() && b_iter != b.end()) {
            if (*a_iter > *b_iter) {
                result.push_back(*a_iter++);
            } else {
                result.push_back(*b_iter++);
            }
        }

        while (a_iter != a.end()) {
            result.push_back(*a_iter++);
        }

        while (b_iter != b.end()) {
            result.push_back(*b_iter++);
        }

        return result;
    }

public:
    Array Solve(const Array & a, const Array & b, const Array & c) {
        return MergeTwoArrays(MergeTwoArrays(a, b), c);
    }
};

int main() {
    MergeThreeArrays mta;
    Array a = {10, 5, 2}, b = {9, 6, 3}, c = {8, 7, 4, 1};

    for (const int & it : mta.Solve(a, b, c)) {
        std::cout << it << ' ';
    }

    std::cout << '\n';

    return 0;
}

