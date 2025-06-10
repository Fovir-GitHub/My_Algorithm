#include <iostream>
#include <string>
#include <vector>

using std::vector, std::string;

vector<vector<vector<string>>> solveNQueen(int n);

void backTracking(int row, int n, vector<vector<string>> & state,
                  vector<vector<vector<string>>> & result,
                  vector<bool> & columns, vector<bool> & dia1,
                  vector<bool> & dia2);

int main() {
    int n = 0;

    while (std::cin >> n) {
        for (const auto & solution : solveNQueen(n)) {
            for (const auto & row : solution) {
                for (const auto & column : row) {
                    std::cout << column << ' ';
                }
                std::cout << '\n';
            }
            std::cout << "\n\n";
        }
    }

    return 0;
}

vector<vector<vector<string>>> solveNQueen(int n) {
    vector<vector<vector<string>>> result;
    vector<vector<string>> state(n, vector<string>(n, "#"));
    vector<bool> dia1(n * 2 - 1, false);
    vector<bool> dia2(n * 2 - 1, false);
    vector<bool> column(n, false);

    backTracking(0, n, state, result, column, dia1, dia2);

    return result;
}

void backTracking(int row, int n, vector<vector<string>> & state,
                  vector<vector<vector<string>>> & result,
                  vector<bool> & columns, vector<bool> & dia1,
                  vector<bool> & dia2) {
    if (row == n) {
        result.push_back(state);
        return;
    }

    for (int col = 0; col < n; col++) {
        int main_dia = row - col + n - 1;
        int sub_dia = row + col;

        if (!columns[col] && !dia1[main_dia] && !dia2[sub_dia]) {
            state[row][col] = "Q";
            columns[col] = dia1[main_dia] = dia2[sub_dia] = true;
            backTracking(row + 1, n, state, result, columns, dia1, dia2);
            state[row][col] = "#";
            columns[col] = dia1[main_dia] = dia2[sub_dia] = false;
        }
    }
}

