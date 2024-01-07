//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool isSafe(int clr, int node, int n, vector<int> &color, bool graph[101][101]){
        for(int i=0; i<n; i++){
            if( i != node && graph[i][node] == 1 && color[i] == clr) return false;
        }
        return true;
    }
    
    bool fun(bool graph[101][101], int m, int n, int node, vector<int> &color){
        if(node == n) return true;  // if color is equal to no of nodes return true.. 
        
        for(int i=1; i<=m; i++){
            if(isSafe(i, node, n, color, graph)){
                color[node] = i;
                if(fun(graph, m, n, node+1, color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        return fun(graph, m, n, 0, color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends