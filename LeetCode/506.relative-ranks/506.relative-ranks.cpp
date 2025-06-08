/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int> & score) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype([](const pair<int, int> & first,
                                   const pair<int, int> & last) {
                           return first.first < last.first;
                       })>
            pq;

        for (int i = 0; i < score.size(); i++)
            pq.push(pair<int, int>(score[i], i));

        vector<string> result(score.size());
        int index = 1;

        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            if (index <= 3) {
                switch (index) {
                case 1:
                    result[top.second] = "Gold Medal";
                    break;
                case 2:
                    result[top.second] = "Silver Medal";
                    break;
                case 3:
                    result[top.second] = "Bronze Medal";
                    break;
                }
            } else
                result[top.second] = to_string(index);

            index++;
            pq.pop();
        }

        return result;
    }
};
// @lc code=end

int main(void) {
    vector<int> scores = {10, 3, 8, 9, 4};
    Solution sol;

    for (const auto & iter : sol.findRelativeRanks(scores))
        cout << iter << '\n';

    return 0;
}