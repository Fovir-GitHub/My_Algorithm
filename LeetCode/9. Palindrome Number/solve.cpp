#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        string number_string("");
        while (x)
        {
            number_string += x % 10 + '0';
            x /= 10;
        }

        int length = number_string.length();

        for (int i = 0; i < (length & 1 ? length / 2 + 1 : length / 2); i++)
            if (number_string[i] != number_string[length - i - 1])
                return false;

        return true;
    }
};

int main(void)
{
    int n = 0;
    Solution sol;

    while (cin >> n)
        cout << sol.isPalindrome(n) << '\n';
}