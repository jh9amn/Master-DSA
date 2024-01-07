// https://leetcode.com/problems/01-matrix/

#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n == 1 && m == 1) return mat;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int count = 0;
        // traversing for add all ones for multi source BFS
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({{i,j},0});
                }
            }
        } 
        // for moving in the four different direction
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            if(mat[r][c] == 1 && vis[r][c] == true ){
                dis[r][c] = d; 
            }

            for(auto it : dir){
                int nr = it.first + r;
                int nc = it.second + c;

                if((nr >= 0 && nr < n && nc >= 0 && nc < m) && vis[nr][nc] == false) {
                    vis[nr][nc] = true;
                    q.push({{nr,nc},d+1});
                } 
            } 
        }
        return dis;  
    }
};