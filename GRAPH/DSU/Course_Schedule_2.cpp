#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& p) {
        vector<vector<int>> graph(N);
        for(auto it : p){
            graph[it[1]].push_back(it[0]);
        }
        queue<int> q;
        // this is InDegree for the Given List
        vector<int> inDegree(N,0);
        for(int i=0; i<N; i++){
            for(auto v : graph[i]){
                inDegree[v]++;
            }
        }
        
        for(int i=0; i<N; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            res.push_back(node);
            q.pop();
            for(auto it : graph[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(res.size() == N) return res;
        return {};
    }  
};
int main(){
    
}