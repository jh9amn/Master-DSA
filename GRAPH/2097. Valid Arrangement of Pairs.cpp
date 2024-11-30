#include<bits/stdc++.h>
using namespace std;
int main(){}

// Heirholzer's Algorithm

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        unordered_map<int, vector<int>> adj;

        // build indegree and outdegree
        unordered_map<int, int > indegree, outdegree;   // key = node, value = indegree / outdegree node

        for(auto it : pairs) {
            int u = it[0];
            int v= it[1];

            // adjecency list
            adj[u].push_back(v);

            outdegree[u]++;
            indegree[v]++;
        }


        // According to Heirholzer's algo, we have to find the start node of graph and perfrom dfs
        // to find startnode = outdegree[node] - indegree[node] == 1.. so startNode = node

        int startNode = pairs[0][0];
        for(auto it : adj){
            int node = it.first;
            // start Node of graph
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
            }
        }

        // node perform dfs / bfs to check every node in graph are visiable only one time and store that Euler pattern
        stack<int> st;
        vector<int> EulerPath;      // Euler Path pattern

        st.push(startNode);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else{       // visited then
                EulerPath.push_back(curr);
                st.pop();
            }
        }

        // correct the direction because of stack
        reverse(begin(EulerPath), end(EulerPath));

        vector<vector<int>> ans;

        // now draw the correct the path with help of eulerpath direction..
        for(int i=0; i<EulerPath.size()-1; i++){
            ans.push_back({EulerPath[i], EulerPath[i+1]});
        }

        return ans;
    }
};