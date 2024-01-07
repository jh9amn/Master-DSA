#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(int Row, int Col, vector<string> &board, int n){
        int col = Col;
        while(col >= 0){
            if(board[Row][col] == 'Q') return false;
            col--;
        }
        
        int row = Row;
        col = Col;
        while(row >= 0 && col >=0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        row = Row;
        col = Col;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;   
    }
    
//     bool isValid(int Row, int Col, vector<string> &board, int n){
//         vector<int> v(n*n,0);
        
//     }
    
    void queen(int col ,vector<vector<string>> &ans, vector<string> &board, int n){
         if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
          if(isValid(row,col,board,n)){
              board[row][col] = 'Q';
              queen(col + 1, ans, board, n);
              board[row][col] = '.';
          }     
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++) board[i] = s;
        queen(0,ans,board,n);
        return ans;
        
    }
};
int main(){

}