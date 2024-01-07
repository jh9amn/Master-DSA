#include<bits/stdc++.h>
using namespace std;
int main(){

}
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V); 
        queue<int> q;
	    for(int i=0; i<V; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    vector<int> res;
	    while(!q.empty()){
	        int node  = q.front();
	        res.push_back(node);
	        q.pop();
	        
	        for(auto adjNode : adj[node]){
	            indegree[adjNode]--;
	            if(indegree[adjNode] == 0) q.push(adjNode);
	        }
	    } 
	    if(res.size() == V) return false; // if no cycle then it is easily topologicaly sorted all the elements
	    return true; // if there is cycle then it can't sort all the elememt...
	    
    }
