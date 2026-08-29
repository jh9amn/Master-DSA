class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        /*
        ** linear ordering of vertices such that if there is an edge between u & v, u always appears before v in the ordering.
        **Topological sort can onluy possible in DAG
        */
        
        unordered_map<int, vector<int>> adj;
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        
        int indegree[V] = {0};
        for(auto it: edges) {
            indegree[it[1]]++;
        }
        
        queue<int>q;
        vector<int> toposort;
        
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) q.push(i); // start the toposort from here
        }
        
        // TC = O(V+E)
        while(!q.empty()){
           int node = q.front();
           q.pop();
          
           toposort.push_back(node);
          
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return toposort;
    }
};


// DFS
// Simple intitution - simply when DFS is completed we are just storing recursion stack..

using vi = vector<int>;
class Solution {
  private:
    // TC = O(V+E)
    void dfs(int node, vi &vis, stack<int> &st, unordered_map<int, vi> &adj) {
        vis[node] = 1;
        
        for(auto it: adj[node]) {
            if(!vis[it]){
                dfs(it, vis, st, adj);
            }
        }
        
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vi> adj;
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        vi vis(V,0);
        stack<int> st;
        
        for(int i=0; i<V; i++) {
            if(vis[i] == 0) {
                dfs(i, vis, st, adj);
            }
        }
        
        vi topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        
        return topo;
    }
};
