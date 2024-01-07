// https://leetcode.com/problems/number-of-islands/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    // VVVI ques..
    void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis){
        vis[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});

        int n = grid.size();
        int m = grid[0].size();

        // for the four different direction
        vector<pair<int,int>> direction{{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // for traversing in all the four direction of the grid
            for(auto dir : direction){
                
                int newRow = dir.first + row;
                int newCol = dir.second + col;
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == '1' && vis[newRow][newCol] == false){
                    q.push({newRow,newCol});
                    vis[newRow][newCol] = true; 
                }
            } 
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == false ){
                    count++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};
int main(){

}