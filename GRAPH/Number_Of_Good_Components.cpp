//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
    
  public:
  
    bool dfs(vector<int> graph[], vector<int> &vis, int start){
        int num = 0; 
        int edges = 0;
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            
            num++;
            edges += graph[i].size();
            
            for(auto it : graph[i]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return num*(num-1) == edges;
    }
    
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int> graph[v+1];
        vector<int> vis(v+1,0);
        
        for(auto x : edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        int ans = 0;
        
        for(int i=1; i<=v; i++){
            if(dfs(graph, vis, i)) 
                ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends