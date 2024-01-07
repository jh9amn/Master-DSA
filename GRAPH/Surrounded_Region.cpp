// https://leetcode.com/problems/surrounded-regions/
#include<bits/stdc++.h>
using namespace std;

int main(){

}

class Solution {
public:
    int n,m;
    int direction[4][2] = {
                    {-1,0},
            {0,-1},         {0,1},
                    {1,0}
    };

    bool isValid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }


    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &vis ){
        vis[i][j] = true;
        for(auto dir : direction){
            int new_row = i + dir[0];
            int new_col = j + dir[1];
            if(isValid(new_row,new_col) && vis[new_row][new_col] == false &&
            board[new_row][new_col] == 'O')
            dfs(new_row, new_col, board, vis);
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        if(n == 1 && m == 1 && board[0][0] == 'O') return; 
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1] == 'O'){
                dfs(i,m-1,board,vis);
            }
        }
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O'){
                dfs(0,j,board,vis);
            }
            if(board[n-1][j] == 'O'){
                dfs(n-1,j,board,vis);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};