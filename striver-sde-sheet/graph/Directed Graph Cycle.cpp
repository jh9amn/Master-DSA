#include<bits/stdc++.h>
using namespace std;

int main() {}


using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tiii = tuple<int, int, int>;


// DFS
class Solution {
  public:
    // TC = O(V+E)
    bool dfs(int start, vi &vis, vi &pathVis, unordered_map<int, vi> &adj) {
        vis[start] = 1;
        pathVis[start] = 1;
        
        for(auto it: adj[start]) {
            if(!vis[it]) {
                if(dfs(it, vis, pathVis, adj)) return true;
            }
            // if the node is previously visited
            // and it has be visited on same path..
            // then cycle
            else if(pathVis[it] == 1) {
                return true;
            }
        }
        pathVis[start] = 0; 
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        /*
        0 - not visited
        1 - visited
        2 - visited and pathVisited
        */
        vi vis(V, 0);
        vi pathVis(V, 0);
        unordered_map<int, vi> adj;     // sc=O(v+E)
        
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adj)) return true;
            }
        }
        
        return false;
    }
};



// BFS

