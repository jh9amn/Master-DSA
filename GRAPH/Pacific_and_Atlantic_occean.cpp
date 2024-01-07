// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;

    bool isValid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m ;
    }

    void dfs(int i, int j, vector<vector<int>>& h, vector<vector<bool>> &vis){
        vis[i][j] = true;
        for(auto it : direction){
            int nr = it[0] + i;
            int nc = it[1] + j;
            
            if( isValid(nr,nc) && vis[nr][nc] == false && h[nr][nc] >= h[i][j]){
                dfs(nr,nc,h,vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n = h.size();
        m = h[0].size();

        vector<vector<int>> v;

        vector<vector<bool>> vis1(n,vector<bool>(m,0));
        vector<vector<bool>> vis2(n,vector<bool>(m,0));
        
        for(int i=0; i<n; i++){
                dfs(i,0,h,vis1);
                dfs(i,m-1,h,vis2);
        }

        for(int j=0; j<m; j++){
                dfs(0,j,h,vis1);
                dfs(n-1,j,h,vis2);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis1[i][j] == true && vis2[i][j] == true) {
                    v.push_back({i,j});
                }
            }
        }
        return v;   
    }
};



class Solution {
public:
    // the four different direction
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;

    // this is checking range if i and j
    bool isValid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m ;
    }

    //  Just BFS for water flow of pacific and atlantic in the four differnt direction
    void water_Move_BFS(queue<pair<int,int>> &q, vector<vector<int>> &h, vector<vector<bool>> &vis){
        while( !q.empty() ){
            int r = q.front().first;
            int c = q.front().second;
            vis[r][c] = true;
            q.pop();
            for(auto it : direction){
                int nr = r + it[0];
                int nc = c + it[1];
                if( isValid(nr,nc) && vis[nr][nc] == false && h[nr][nc] >= h[r][c] ){
                    q.push({nr,nc});
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n = h.size();
        m = h[0].size();

        vector<vector<int>> res;
        
        // pacific and atlantic ocean water flow
        vector<vector<bool>> pacific_vis(n,vector<bool>(m,0));
        vector<vector<bool>> atlantic_vis(n,vector<bool>(m,0));

        // queue for multi source bfs from pacific and atlantic
        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;

        // pushing ele in queue for multi source bfs from atlantic and pacific
        for(int i=0; i<n; i++){
            pacific.push({i,0});
            atlantic.push({i,m-1});
        }
        for(int j=0; j<m; j++){
            pacific.push({0,j});
            atlantic.push({n-1,j});
        }
       
        // multisource BFS calling to check water flow
        water_Move_BFS(pacific, h, pacific_vis);
        water_Move_BFS(atlantic, h, atlantic_vis);

    // the common point of water flow of both oceans
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(atlantic_vis[i][j] && pacific_vis[i][j] ){
                res.push_back({i,j});
            }
        }
    }
    return res;   
    }
};