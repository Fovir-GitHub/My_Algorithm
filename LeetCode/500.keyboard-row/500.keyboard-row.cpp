/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string> & words) {
        const static unordered_map<char, int> keyboard_map = {
            {'q', 0}, {'w', 0}, {'e', 0}, {'r', 0}, {'t', 0}, {'y', 0},
            {'u', 0}, {'i', 0}, {'o', 0}, {'p', 0}, {'a', 1}, {'s', 1},
            {'d', 1}, {'f', 1}, {'g', 1}, {'h', 1}, {'j', 1}, {'k', 1},
            {'l', 1}, {'z', 2}, {'x', 2}, {'c', 2}, {'v', 2}, {'b', 2},
            {'n', 2}, {'m', 2},
        };

        vector<string> result;
        for (const string & str : words) {
            bool flag = true;
            for (int i = 1; i < str.size(); i++)
                if (keyboard_map.at(tolower(str[i])) !=
                    keyboard_map.at(tolower(str[i - 1]))) {
                    flag = false;
                    break;
                }

            if (flag)
                result.push_back(str);
        }

        return result;
    }
};
// @lc code=end

int main(void) {
    string str[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    for (int i = 0; i < 3; i++) {
        string temp = str[i];
        for (int j = 0; j < temp.size(); j++)
            printf("{'%c',%d},", temp[j], i);
    }

    return 0;
}