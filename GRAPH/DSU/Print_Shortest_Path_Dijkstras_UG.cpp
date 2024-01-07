//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        
        for(int i = 0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        // inserting in Adj list..
        // for(auto it : edges){
        //     adj[it[0]].push_back({it[1],it[2]});
        //     adj[it[1]].push_back({it[0],it[2]});
        // }
        
        vector<int> distance(n+1,1e9);
        distance[1] = 0;
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});     // here, 0 is the distance to reach node 1 from node 1....
        
        // Dijkstra's Algorithm
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgeNode = it.first;
                int edgeWeight = it.second;
                
                if(dis + edgeWeight < distance[edgeNode]){
                    distance[edgeNode] = dis + edgeWeight;
                    parent[edgeNode] = node;        // // inserting the parent of adjecent Node..
                    pq.push({distance[edgeNode],edgeNode});
                } 
            }
        }
        // if never reach target Node..
        if(distance[n] == 1e9) return {-1};
        
        // Back Tracking Path using Parent Vector..
        vector<int> shortestPath;
        while(parent[n] != n){
            shortestPath.push_back(n);
            n = parent[n];
        }

        shortestPath.push_back(1);
        reverse(shortestPath.begin(), shortestPath.end());
        return shortestPath;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends