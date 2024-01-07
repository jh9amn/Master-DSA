//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        int edge = flights.size();
        
        for(int i=0; i<edge; i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
         
        vector<int> cost(n,1e9);
        cost[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src,0}}); // ({stop,{node,cost}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int ct = it.second.second;  // ct = cost
                        
            for(auto x : adj[node]){
                int adjNode = x.first;
                int adjNodeCost = x.second;
                
                if(ct + adjNodeCost < cost[adjNode]){
                    cost[adjNode] = ct + adjNodeCost;
                    q.push({stops+1,{adjNode,cost[adjNode]}});
                }
            }
            // // all the adjecent_Stop (k < stops) fill 
            if(q.front().first > K)  return (cost[dst] != 1e9) ? cost[dst] : -1;  
        }
        if(cost[dst] == 1e9) return -1;
        return cost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends