// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool check(int src, vector<int> &color, vector<int> adj[]){
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else{
                    if(color[it] == color[node]) return false;
                }
            }
        }
        return true;
    }
    
    
public:
	bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V,-1);
        for(int i=0; i<V; i++){
            if(color[i] == -1) {
                if(check(i,color,adj) == false ) return false;
            }
        }
        return true;
	}
};

// LEETCODE
// class Solution {
// private:
// bool check(int src, vector<int> &color, vector<int> adj[]){
//     queue<int> q;
//     q.push(src);
//     color[src] = 0;
//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         for(auto it : adj[node]){
//             if(color[it] == -1){
//                 color[it] = !color[node];
//                 q.push(it);
//             }
//             else{
//                 if(color[it] == color[node]) return false;
//             }
//         }
//     }
//     return true;
// }
    
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> adj[n];  // i -> graph[i] has connections
//         for(int i=0; i<n; i++){
//             for(auto it : graph[i]){
//                 adj[i].push_back(it);
//                 adj[it].push_back(i);
//             }
//         }
        
//         vector<int> color(n,-1);
//         for(int i=0; i<n; i++){
//             if(color[i] == -1) {
//                 if(check(i,color,adj) == false ) return false;
//             }
//         }
//         return true;
//     }
// };

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends

