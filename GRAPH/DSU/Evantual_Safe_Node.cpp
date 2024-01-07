#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> inDegree(n,0);
        
        // creating a adjList having the edges in the reverse order
        for(int i=0; i<n; i++){
            for(int j=graph[i].size()-1; j>=0; j--){
                adjRev[graph[i][j]].push_back(i);
            }
        }
        
        // puting the no of inDegree edges to that node..
        for(int i=0; i<n; i++){
            for(auto it : adjRev[i]){
                inDegree[it]++;
            }
        }
    
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        vector<int> safeNode;
        // BFS TopoLogical 
        while(!q.empty()){
            int node = q.front();
            safeNode.push_back(node);
            q.pop();
            
            for(auto it : adjRev[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        
        sort(safeNode.begin(), safeNode.end());
        return safeNode;  
    }
};

int main(){

}