/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto iter : s) {
            if (iter == '(' || iter == '[' || iter == '{')
                st.push(iter);
            else {
                if (st.empty() || (iter == ')' && st.top() != '(') ||
                    (iter == ']' && st.top() != '[') ||
                    (iter == '}' && st.top() != '{'))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
// @lc code=end

int main(void) {
    string s;
    Solution sol;

    while (cin >> s)
        cout << sol.isValid(s) << '\n';

    return 0;
}