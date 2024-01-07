#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        // Simple BFS call
        void bfs(int start, vector<int> list[], vector<bool> &vis){
            queue<int> q;
            q.push(start);
            vis[start] = true;
            while(!q.empty()){
                start = q.front();
                q.pop();
                for(auto it : list[start]){
                    if(vis[it] == false){
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }



        // simple DFS solution
        void dfs(int start, vector<int> list[], vector<bool> &vis){
            vis[start] = true;
            for(auto it : list[start]){
                if(vis[it] != true)
                    dfs(it,list,vis);
            }
        }

        int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // converting adjacency matrix into adjacency list
        vector<int> list[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j) {   // i != j means not self node allow
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }

        // passing BFS for no of connected componenet
        vector<bool> vis(n,false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                count++;
                dfs(i,list,vis);
            } 
        }
        return count;  
    }
};

class DSU {
 public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int find_parent(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_parent(parent[node]);
    }
    
    void UnionBySize(int u,int v){
        u = parent[u];
        v = parent[v];
        
        if(u == v) return;
        if(size[u] > size[v]){
            parent[v] = u;
            size[u] += size[v];
        }
        else{
            parent[u] = v;
            size[v] += size[u];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    ds.UnionBySize(i,j);
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
           if(ds.parent[i] == i) count++; 
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.findCircleNum(adj) << endl;
    }
    return 0;
}

