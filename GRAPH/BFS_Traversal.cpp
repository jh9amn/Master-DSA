#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    queue<int> q;
    vector<bool> vis(V,false);
    vis[0] = true;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
            int curr = q.front();
            bfs.push_back(curr);
            q.pop();
        for(auto it : adj[curr]){
            if(vis[it] == false){
            vis[it] = true;
            q.push(it);   
            }
        }
    }
    return bfs;
}




    int main(){

    }