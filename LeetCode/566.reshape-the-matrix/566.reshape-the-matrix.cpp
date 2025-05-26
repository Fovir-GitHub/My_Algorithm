/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> & mat, int r, int c)
    {
        int m = mat.size(), n = mat[0].size();

        if (m * n != r * c)
            return mat;

        int                 row = 0, column = 0;
        vector<vector<int>> result(r, vector<int>(c, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[row][column] = mat[i][j];

                column++;
                row += (column / c);
                column %= c;
            }
        }

        return result;
    }
};
// @lc code=end
