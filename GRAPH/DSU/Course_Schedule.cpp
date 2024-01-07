#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> graph(numCourses);
        for(auto it : p){
            graph[it[1]].push_back(it[0]);
        }
        queue<int> q;
        // this is InDegree for the Given List
        vector<int> inDegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto v : graph[i]){
                inDegree[v]++;
            }
        }
        
        for(int i=0; i<numCourses; i++){
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
        if(res.size() == numCourses) return true;
        return false;
    }
};
int main(){

}