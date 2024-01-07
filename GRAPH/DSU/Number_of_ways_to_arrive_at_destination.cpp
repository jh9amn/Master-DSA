//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,long long>> adj[n];
        int edges = roads.size();
        // for(int i=0; i<edges; i++){
        //     adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        //     adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        // }
        
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<long long> dist(n,LLONG_MAX);
        dist[0] = 0;
        vector<int> ways(n,0);
        ways[0] = 1;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        
        pq.push({0,0});         // {dis,Node}
        
        int mod = (int)(1e9 + 7);
        
        while(!pq.empty()){
            auto it = pq.top();
            long long dis = it.first ;
            int node = it.second;
            pq.pop();
            
            // if(node = n-1) return ways[n-1];

            for(auto x : adj[node]){
                int adjNode = x.first;
                int adjWt = x.second;
                
                if(adjWt + dis < dist[adjNode]){
                    dist[adjNode] = dis + adjWt;
                    ways[adjNode] = ways[node];
                    pq.push({dis + adjWt, adjNode});
                }
                else if(adjWt + dis == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
         return (ways[n-1] % mod);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends