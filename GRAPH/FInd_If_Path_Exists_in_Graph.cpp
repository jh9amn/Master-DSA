#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &gr, vector<int> &vis, int s, int d){
        if(vis[s] == 1) return;
        vis[s] = 1;
        
        for(auto node : gr[s]){
            if(!vis[node])
            dfs(gr, vis, node, d);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n,0);
        vector<vector<int>> gr(n);
        
        for(auto it : edges){
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        
        dfs(gr, vis, source, destination);
        return vis[destination];
    }
};

int main(){


}