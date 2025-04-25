/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
private:
    int row, column;

public:
    int islandPerimeter(vector<vector<int>> & grid)
    {
        row    = grid.size();
        column = grid[0].size();

        int i, j, perimeter = 0;

        for (i = 0; i < row; i++)
        {
            bool flag = false;
            for (j = 0; j < column; j++)
                if (grid[i][j])
                {
                    flag = true;
                    break;
                }

            if (flag)
                break;
        }

        perimeter += dfs(grid, i, j);

        return perimeter;
    }

    int dfs(vector<vector<int>> & grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= row || j >= column || !grid[i][j])
            return 1;
        else if (grid[i][j] == -1)
            return 0;

        grid[i][j] = -1;

        return (dfs(grid, i + 1, j) + dfs(grid, i - 1, j) +
                dfs(grid, i, j + 1) + dfs(grid, i, j - 1));
    }
};
// @lc code=end

int main(void)
{
    // vector<vector<int>> grid = {{1}};

    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
    };

    Solution sol;

    cout << sol.islandPerimeter(grid) << '\n';

    return 0;
}