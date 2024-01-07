//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// PRIM'S ALGORITHM
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}});  // ({wt,{node,parent}});
        
        vector<int> vis(V,0);
        int sum = 0;
        
        vector<pair<int,int>> MST;
        // MST is Done using the Greedy Approch means we always chose that path which has the least edgeWeight
        // and maintanig the structure of node which are given, Just draw that edge to able to visit all given
        // node at minimum weight use...
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            // MST using PRIM ALGORITHM..
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            
            // this for MST Node from where to where...
            MST.push_back({parent,node});
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgWt = it[1];
                if(!vis[adjNode]) pq.push({edgWt,{adjNode,node}});
            }
        }
        return sum;
    }
};

//  KRUSKAL'S ALGORITHM using DSU TO FIND MST(minimum spannig tree)
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


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        // Storig And Sorting The ele in PQ in terms of Wt..
        // vector<pair<int,pair<int,int>>> pq;
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                int node = it[0];
                int wt = it[1];
                pq.push({wt,{i,node}});  // {wt , node, adjNode}
            }
        }

        DSU ds(V);
        int weight = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.find_parent(u) == ds.find_parent(v)) continue;  // if both have same parent then continue..
            ds.UnionBySize(u,v);
            weight += wt;
        }
        return weight;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends