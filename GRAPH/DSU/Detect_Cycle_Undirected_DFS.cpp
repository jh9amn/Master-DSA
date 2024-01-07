//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private: 
    bool detectCycle(vector<bool> &vis, int src, int parent, vector<int> adj[]){
        vis[src] = true;
        for(auto adjNode : adj[src]){
            if(!vis[adjNode]){
                if(detectCycle(vis,adjNode,src,adj) == true) return true;
            }
            else{
                if(parent != adjNode) return true; // if adjNode is visited and Not parent then there is cycle..
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++){     //for different Componenets..
            if(vis[i] == false){
                if(detectCycle(vis,i,-1,adj) == true) return true;
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