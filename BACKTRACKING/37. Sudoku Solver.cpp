#include<bits/stdc++.h>
using namespace std++;

int main(){
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        function<bool(int, int, char)> isValid = [&](int row, int col, char c) {
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == c)
                    return false;
                if (board[row][i] == c)
                    return false;
                if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                    return false;
            }
            return true;
        };

        function<bool(int, int)> solve = [&](int i, int j) {
            if (i == 9)
                return true;
            if (j == 9)
                return solve(i + 1, 0);

            // skip that cell which is not '.'
            if (board[i][j] != '.')
                return solve(i, j + 1);

            for (char c = '1'; c <= '9'; c++) {
                if (isValid(i, j, c)) {
                    board[i][j] = c;
                    if (solve(i, j + 1))
                        return true;
                    board[i][j] = '.';
                }
            }

            return false;
        };
        solve(0, 0);
    }
};
