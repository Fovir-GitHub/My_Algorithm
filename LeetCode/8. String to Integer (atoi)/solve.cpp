#include <cctype>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

#define DEBUG cout << "DEBUG" << '\n'

class Solution
{
public:
    int myAtoi(string s)
    {
        int length = s.length();
        if (length == 0)
            return 0;

        long result         = 0;
        int  start_position = 0;

        // remove white space
        while (start_position < length && s[start_position] == ' ')
            start_position++;

        if (!isdigit(s[start_position]) && s[start_position] != '-' &&
            s[start_position] != '+')
            return 0;

        bool negative_number = s[start_position] == '-';

        for (int i = (negative_number || s[start_position] == '+'
                          ? start_position + 1
                          : start_position);
             i < length; i++)
        {
            if (!isdigit(s[i]))
                break;

            result = result * 10 + s[i] - '0';

            if (negative_number)
            {
                if (-result < INT_MIN)
                    return INT_MIN;
            }
            else if (result > INT_MAX)
                return INT_MAX;
        }

        return negative_number ? -result : result;
    }
};

int main(void)
{
    Solution sol;
    string   input;
    while (cin >> input) cout << sol.myAtoi(input) << '\n';

    return 0;
}