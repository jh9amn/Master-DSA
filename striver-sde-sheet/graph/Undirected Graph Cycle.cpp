#include <bits/stdc++.h>
#include <cmath>
using namespace std;

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


#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
#define pb push_back

void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


// using DFS
// TC = O(V+E)
class Solution {
  private:
    bool dfs(unordered_map<int, vi> &adj, int parent, int node, vector<bool> &vis) {
        vis[node] = true;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = true;
                if(dfs(adj, node, it, vis)) return true;
            }
            else if(vis[it] && it != parent) return true;
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,vi> adj;
        for(auto it: edges) {
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }
        
        vector<bool> vis(V+1, false);
            
        for(int i=0; i<V; i++){
            if(!vis[i]){
                // dummy parent in start as -1 when it came before
                if(dfs(adj, -1, i, vis)) return true;
            }
        }
        
        return false;
    }
};


// Using BFS
// if it is a tree, every node should be visited once only.
// if we come to the node that we already visted, then it has cycle..
// if we start parent to two different direction, and in any case if we came to a particular node from direnction then their a cycle in it,
// TC = O(V+E)
class Solution {    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,vi> adj;
        for(auto it: edges) {
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }
        
        vector<int> vis(V, 0);
        for(int start=0; start<V; start++) {
            if(vis[start]) continue;
            queue<pair<int, int>> q;
            q.push({-1, start});    // parent and node
            vis[start] = 1;
            while(!q.empty()) {
                auto it = q.front();
                q.pop();
                int parent = it.first;
                int node = it.second;
                for(auto a : adj[node]) {
                    if(a == parent) continue; 
                    if(vis[a]) return true;
                    vis[a] = 1;
                    q.push({node, a});
                }
            }
        }
        return false;
    }
};
