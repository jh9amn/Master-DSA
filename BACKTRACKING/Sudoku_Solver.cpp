#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>> &board, int val){
        
        for(int row = 0; row < 9; row++){
            if(board[row][j] - '0' == val) return false;
        }
        
        for(int col = 0; col < 9; col++){
            if(board[i][col] - '0' == val) return false;
        }
        
        // finding the subBox starting index
        int x = (i/3) * 3;  
        int y = (j/3) * 3;
        
        for(int br = x; br < x + 3; br++ ){
            for(int bc = y; bc < y + 3; bc++){
                if(board[br][bc] - '0' == val ) return false;
            }
        }
        return true;
    }
    
    
    bool sudoku(int i,int j, vector<vector<char>> &board){
        int n = board.size();
        int m = board[0].size();
        
        // Base Case
        if( i == 9 ) return true;
        if( j == 9 )   return sudoku( i+1, 0, board);
        if(board[i][j] != '.')  return sudoku( i, j+1, board);
        
        for(int val = 1; val <= 9; val++){
            if(isValid( i, j, board, val)){
                board[i][j] = '0' + val;         // int into charactor
                bool res = sudoku(i, j+1, board);
                if(res == true) return res;
                board[i][j] = '.';
            }
        }
        return false;   
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(0,0,board);
    }
};

int main(){

}