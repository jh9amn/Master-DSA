// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detectCycle(vector<bool> &vis, int src, vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = true;
        while(q.size() != 0){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNodes : adj[node]){
                if(vis[adjNodes] == false){
                    vis[adjNodes] = true;
                    q.push({adjNodes,node});
                }
                else {
                    if(parent != adjNodes) return true;  // if the adjecent Node are visited and it is not parent
                }                                       // then there is cycle...
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++){         //for different Componenets..
            if(!vis[i]){
                if(detectCycle(vis,i,adj) == true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends