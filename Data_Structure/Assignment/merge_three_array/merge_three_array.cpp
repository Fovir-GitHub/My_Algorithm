#include <iostream>
#include <vector>

using Array = std::vector<int>;

class MergeThreeArrays {
private:
public:
    Array Solve(const Array & a, const Array & b, const Array & c) {
        Array result;
        auto first_begin = a.begin(), second_begin = b.begin(),
             third_begin = c.begin();
        auto first_end = a.end(), second_end = b.end(), third_end = c.end();

        while (first_begin != first_end && second_begin != second_end &&
               third_begin != third_end) {
            if (*first_begin > *second_begin && *first_begin > *third_begin) {
                result.push_back(*first_begin++);
            } else if (*second_begin > *first_begin &&
                       *second_begin > *third_begin) {
                result.push_back(*second_begin++);
            } else {
                result.push_back(*third_begin++);
            }
        }

        if (first_begin == first_end) {
            first_begin = third_begin;
            first_end = third_end;
        } else if (second_begin == second_end) {
            second_begin = third_begin;
            second_end = third_end;
        }

        while (first_begin != first_end && second_begin != second_end) {
            result.push_back((*first_begin > *second_begin ? *first_begin++
                                                           : *second_begin++));
        }

        while (first_begin != first_end) {
            result.push_back(*first_begin++);
        }

        while (second_begin != second_end) {
            result.push_back(*second_begin++);
        }

        return result;
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
