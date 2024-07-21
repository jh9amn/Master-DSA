#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:

    void topo_sort_dfs(int node, unordered_map<int, vector<int> > &adj, vector<int> &vis, stack<int> &st, bool &isCycle){
        vis[node] = 1; // marking node as visiting

        for (int &nbr : adj[node]){
            if(!vis[nbr]){
                topo_sort_dfs(nbr, adj, vis, st, isCycle);
            }
            else if(vis[nbr] == 1){
                isCycle = true;
                return;
            }
        }

        vis[node] = 2;  // visited Successfully
        st.push(node);   // valid node and can added
    }

    vector<int> topoSort(vector<vector<int>> &edges, int n){
        unordered_map<int, vector<int> >adj;
        stack<int> st;
        vector<int> order;

        // O : not visited
        // 1 : visiting Now
        // 2 : visited previously

        vector<int> vis(n+1, 0);
        bool isCycle = false;

        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }


        for(int i=1; i<=n; i++){
            if(vis[i] == 0) {
                topo_sort_dfs(i, adj, vis, st, isCycle);
                if(isCycle) return {};
            }
        }

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderCols = topoSort(colConditions, k);

        // We found Cycle that's why topo Order is Empty
        if(orderRows.empty() || orderCols.empty()) return {};
        
        vector<vector<int>> ans(k, vector<int> (k,0));
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(orderRows[i] == orderCols[j]) {
                    ans[i][j] = orderRows[i];
                }
            }
        }

        return ans;
    }
};