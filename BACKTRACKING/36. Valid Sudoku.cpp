#include<bits/stdc++.h>
using namespace std;

int main(){
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        function<bool(int, int, char)> isValid = [&](int row, int col, char c) {
            // no same charactor in this square...
            for (int i = 0; i < 9; i++) {
                // skip that cell
                if (i != row && board[i][col] == c)
                    return false;
                if (i != col && board[row][i] == c)
                    return false;

                int r = 3 * (row / 3) + i / 3;
                int c2 = 3 * (col / 3) + i % 3;

                if ((r != row || c2 != col) && board[r][c2] == c)
                    return false;
            }
            return true;
        };


        function<bool()> solve = [&]() {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        if (!isValid(i, j, board[i][j])) {
                            return false;
                        }
                    }
                }
            }
            // no need any modification return true
            return true;
        };
        return solve();
    }
};
