//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* - Disjoint Union Tree = Tree1 + Tree2
   - any node in tree1 is not common to any Node in tree2
   - if I take union of tree1 and tree2, get my original tree
   
*/


class Solution {
public:
    int ans = 0;
    int dfs(vector<int> adj[], vector<int> &vis, int i){
        vis[i] = 1;
        int count = 0;
        
        for(auto it : adj[i]){
            if(vis[it] == 0){
                int res = dfs(adj, vis, it);
                if(res % 2 == 0) ans++;
                else count += res;
            }
        }
        
        // because we counting the root too..
        return count + 1;
    }
    
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    vector<int> adj[n];
	    
	    for(int i=0; i<edges.size(); i++){
	        adj[edges[i][0]-1].push_back(edges[i][1]-1);
	        adj[edges[i][1]-1].push_back(edges[i][0]-1);
	    }
	    
	    vector<int> vis(n,0);
	    
	    dfs(adj, vis, 0);
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends