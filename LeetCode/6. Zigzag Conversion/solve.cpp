#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    // string convert(string s, int numRows)
    // {
    //     if (numRows == 1)
    //         return s;
    //     vector<vector<char>> v(numRows);
    //     bool go_down = true;
    //     int length = s.length();
    //     int current_row = 0;
    //     string result("");

    //     for (int i = 0; i < length; i++)
    //     {
    //         v[current_row].push_back(s[i]);

    //         if (current_row == numRows - 1)
    //             go_down = false;
    //         if (current_row == 0)
    //             go_down = true;

    //         if (go_down)
    //             current_row++;
    //         else
    //             current_row--;
    //     }

    //     for (auto & x : v)
    //         for (auto & y : x)
    //             result += y;

    //     return result;
    // }

    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;

        vector<string> v(numRows, "");

        int current_row = 0;
        int length = s.length();
        bool go_down = true;

        for (int i = 0; i < length; i++)
        {
            v[current_row] += s[i];

            if (go_down)
                current_row++;
            else
                current_row--;

            if (current_row == numRows - 1 || current_row == 0)
                go_down = !go_down;
        }

        string result = "";
        for (auto & x : v)
            result += x;

        return result;
    }
};

int main(void)
{
    string input = "AB";
    int n = 1;
    Solution sol;

    cout << sol.convert(input, n) << endl;

    return 0;
}