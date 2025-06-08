#include <climits>
#include <iostream>
#include <vector>

using Array = std::vector<int>;

Array mergeThreeArray(const Array & a, const Array & b, const Array & c);

int main(void) {
    Array a = {9, 7, 5}, b = {8, 6, 2}, c = {10, 4, 1};
    Array result = mergeThreeArray(a, b, c);

    for (const int & it : result)
        std::cout << it << ' ';
    std::cout << '\n';

    return 0;
}

Array mergeThreeArray(const Array & a, const Array & b, const Array & c) {
    Array merged_array;
    Array::const_iterator a_iter = a.begin(), b_iter = b.begin(),
                          c_iter = c.begin();

    while (a_iter != a.end() || b_iter != b.end() || c_iter != c.end()) {
        int a_value = (a_iter == a.end() ? INT_MIN : *a_iter);
        int b_value = (b_iter == b.end() ? INT_MIN : *b_iter);
        int c_value = (c_iter == c.end() ? INT_MIN : *c_iter);

        if (a_value > b_value && a_value > c_value)
            merged_array.push_back(*a_iter++);
        else if (b_value > c_value && b_value > a_value)
            merged_array.push_back(*b_iter++);
        else
            merged_array.push_back(*c_iter++);
    }

    return merged_array;
}
