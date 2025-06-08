#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int max_left = 0, max_right = 0;
        for (int i = 0; i < length; i++) {
            int length1 = expandAround(s, i - 1, i + 1);
            int length2 = expandAround(s, i, i + 1);
            int max_length = max(length1, length2);

            if (max_length > max_right - max_left) {
                max_left = i - (max_length - 1) / 2;
                max_right = i + max_length / 2;
            }
        }
        return s.substr(max_left, max_right - max_left + 1);
    }

    int expandAround(string & s, int left, int right) {
        int length = s.length();
        while (left >= 0 && right < length && s[left] == s[right])
            left--, right++;

        return right - left - 1;
    }
};

int main(void) {
    string s("");
    Solution solution;

    std::cin >> s;
    std::cout << solution.longestPalindrome(s);

    return 0;
}