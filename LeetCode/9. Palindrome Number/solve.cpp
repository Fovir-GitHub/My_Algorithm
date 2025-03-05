#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // bool isPalindrome(int x)
    // {
    //     if (x < 0)
    //         return false;

    //     string number_string("");
    //     while (x)
    //     {
    //         number_string += x % 10 + '0';
    //         x /= 10;
    //     }

    //     int length = number_string.length();

    //     for (int i = 0; i < (length & 1 ? length / 2 + 1 : length / 2); i++)
    //         if (number_string[i] != number_string[length - i - 1])
    //             return false;

    //     return true;
    // }

    // bool isPalindrome(int x)
    // {
    //     if (x < 0)
    //         return false;

    //     int reverse_number = 0;
    //     int copy_number = x;

    //     while (copy_number)
    //     {
    //         reverse_number = reverse_number * 10 + copy_number % 10;
    //         copy_number /= 10;
    //     }

    //     return reverse_number == x;
    // }

    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        int reverse_number = 0;

        while (x > reverse_number)
        {
            reverse_number = reverse_number * 10 + x % 10;
            x /= 10;
        }

        return (x == reverse_number) || (x == reverse_number / 10);
    }
};

int main(void)
{
    int      n = 0;
    Solution sol;

    while (cin >> n) cout << sol.isPalindrome(n) << '\n';

    return 0;
}