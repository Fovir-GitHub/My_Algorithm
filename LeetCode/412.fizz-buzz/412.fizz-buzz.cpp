/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer(n);

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            if (j % 3 == 0 && j % 5 == 0)
                answer[i] = "FizzBuzz";
            else if (j % 3 == 0)
                answer[i] = "Fizz";
            else if (j % 5 == 0)
                answer[i] = "Buzz";
            else
                answer[i] = to_string(j);
        }

        return answer;
    }
};
// @lc code=end

int main(void) {
    int n;
    Solution sol;

    while (cin >> n)
        for (auto it : sol.fizzBuzz(n))
            cout << it << '\n';

    return 0;
}