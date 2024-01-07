//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
//   private:
//     void topo_dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
//         vis[node] = 1;
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 topo_dfs(it,vis,adj,st);
//             }
//         }
//         st.push(node);
//     }
    
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        
        // creating adj list
        for(int i=0; i<M; i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        // for(auto it : edges){
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }
        
        vector<int> vis(N,0);
        vector<int> dis(N,1e9);
        dis[src] = 0;
        // stack<int> st;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int top = q.front();
            q.pop();

        if(dis[top] != 1e9){
            for(auto it : adj[top]){
                if(dis[top] + 1 < dis[it]){
                    dis[it] = dis[top] + 1;
                    q.push(it);
                }
             }
          }
        }
        
        
        // for(int i=0; i<N; i++){
        //     if(!vis[i]){
        //         topo_dfs(i,vis,adj,st);
        //     }
        // }
        
        // while(!st.empty()){
        //     int top = st.top();
        //     st.pop();
            
        // if(dis[top] != 1e9){
        //      for(auto it : adj[top]){
        //         if(dis[top] + 1 < dis[it]){
        //             dis[it] = dis[top] + 1;
        //         }
        //      }
        //   }
        // }
        
        
        for(int i=0; i<dis.size(); i++){
            if(dis[i] == 1e9) dis[i] = -1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends