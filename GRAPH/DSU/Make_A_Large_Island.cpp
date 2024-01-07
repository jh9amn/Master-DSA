//{ Driver Code Starts
// Initial Template for C++

// https://leetcode.com/problems/making-a-large-island/
// https://practice.geeksforgeeks.org/problems/maximum-connected-group/1


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DSU {
  public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int find_par(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_par(parent[x]);
    }
    
    void Union(int x, int y){
        x = find_par(x);
        y = find_par(y);
        
        if(x == y) return;
        if(size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        }
        else{
            parent[x] = y;
            size[y] += size[x];
        }
    }
};


class Solution {
  public:
  
  bool isValid(int adjRow, int adjCol, int n){
        return adjRow >=0 && adjCol >= 0 && adjRow < n && adjCol < n;
    }
    
    
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        
        // For the Checking AdjNode to All the Four direction
        
        vector<vector<int>> dir = {
            {0,1}, {1,0}, {-1,0},{0,-1}
        };
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(auto it : dir){
                        int adjRow = i + it[0];
                        int adjCol = j + it[1];
                        if(isValid(adjRow, adjCol, n) && grid[adjRow][adjCol] == 1) {
                            int nodeNum = i * n + j;
                            int adjNodeNum = adjRow * n + adjCol;
                            ds.Union(nodeNum, adjNodeNum);
                        }
                    }
                }
            }
        }
        
        int largeIsland = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                unordered_set<int> s;
                if(grid[i][j] == 0){
                    for(auto it : dir){
                        int adjRow = i + it[0];
                        int adjCol = j + it[1];
                        
                        if( isValid(adjRow, adjCol, n) && grid[adjRow][adjCol] == 1) {
                            int adjNodeNum = adjRow * n + adjCol;
                            s.insert(ds.find_par(adjNodeNum));
                        }
                    }
                }
                int total = 0;
                for(auto it : s){
                    total += ds.size[it];
                }
                largeIsland = max(total+1 , largeIsland);
            }
        }
        // if all the cell value is 1 then 
        for(int cellNo = 0; cellNo < n*n; cellNo++){
            largeIsland = max(largeIsland , ds.size[ds.find_par(cellNo)]);
        }
        return largeIsland ; 
    }
};

    


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends