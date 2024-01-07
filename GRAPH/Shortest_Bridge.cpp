// https://leetcode.com/problems/shortest-bridge/description/
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int n,m;
    // the four direction 
    int direction[4][2] = {

                {-1,0},
        {0,-1},          {0,1},
                {1,0}

    };

    bool isValid(int i,int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }


    // dfs for finding & visiting the first Island
    void dfs(int i,int j,vector<vector<int>> &grid, vector<vector<bool>> &vis ,queue<pair<pair<int,int>,int>> &q){
        if(!isValid(i,j) || vis[i][j] == true || grid[i][j] == 0){
            return;
        }
            vis[i][j] = true;
            // for multi source BFS (pushing all 1st Island element in queue) 
            q.push({{i,j},0});
            for(auto it : direction){
                int i_ = it[0] + i;
                int j_ = it[1] + j;
                dfs(i_,j_,grid,vis,q);
            }
    }


    // Bfs for finding 2nd Island & shortest dis between the first Islanf and Second one ....
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, queue<pair<pair<int,int>,int>> &q){
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for(auto dir : direction){
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                if(isValid(new_r, new_c) && vis[new_r][new_c] == false) { 
                    if(grid[new_r][new_c] == 1)  return dis;                                               
                    vis[new_r][new_c] = true;
                    q.push({{new_r,new_c},dis+1});
                }
            }
        } return 0;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;
    
        int shortest_Dis = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 ){
                    dfs(i,j,grid,vis,q); 
                    return bfs(grid,vis,q);
                }
            }
        }
        return -1 ;
    }
};

int main(){

}