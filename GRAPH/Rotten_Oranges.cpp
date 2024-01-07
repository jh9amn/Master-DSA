#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tm = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2 ){
                    vis[i][j] = true;
                    q.push({{i,j},0});
                }
            }
        }
        vector<pair<int,int>> direction{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            tm = max(time,tm);
            for(auto dir : direction){
                int newRow = dir.first + row;
                int newCol = dir.second + col;
                if((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < m) && 
                vis[newRow][newCol] == false && grid[newRow][newCol] == 1 ){
                    vis[newRow][newCol] = true;
                    q.push({{newRow,newCol}, time+1 });
                }
            } cout<<tm<<" ";
        } 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 1 && vis[i][j] == false) 
                return -1 ;
            }
        }  
        return tm;
    }
};