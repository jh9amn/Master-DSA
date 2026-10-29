/*
Tarjan's ALgorithms
dt = discovery time
low =  lowest dt of all reachable node (including node itself, ignoring parent)
*/


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

class Solution {
private: 
    int timer = 1;
private:
    void dfs(int node, int parent, vi &vis, vvi &bridges, int dt[], int low[], vi adj[]) {
        vis[node] = 1;
        dt[node] = low[node] = timer;
        timer++;

        for(auto it: adj[node]) {
            if(it == parent) continue;
            if(vis[it] == 0) {
                dfs(it, node, vis, bridges, dt, low, adj);
                low[node] = min(low[node], low[it]);

                if(low[it] > dt[node]) {
                    bridges.pb({it, node});
                }
            }
            else {
                low[node] = min(low[it], low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vi adj[n];

        for(auto it: connections) {
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }

        int dt[n]; // discovery time
        int low[n]; // lowest discovery time apart from parents
        vi vis(n, 0);


        vvi bridges;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, bridges, dt, low, adj);
            }
        }
        
        return bridges;
    }
};
