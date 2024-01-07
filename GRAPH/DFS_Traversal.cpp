// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/0
#include<bits/stdc++.h>
using namespace std;
void dfs(int curr, bool vis[], vector<int> adj[], vector<int> &res){
    vis[curr] = 1;
    res.push_back(curr);
    for(auto it : adj[curr]){
        if(vis[it] == false){
            dfs(it,vis,adj,res);
        }
    }
}
// public:
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    bool vis[V] = {false};
    vector<int> res;
    dfs(0,vis,adj,res);
    return res;
}



int main(){

}