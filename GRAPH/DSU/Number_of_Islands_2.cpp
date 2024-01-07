//{ Driver Code Starts
// Initial Template for C++

// https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DSU {
  public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) parent[i] = i;
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
            size[x]++;
        }
        else{
            parent[x] = y;
            size[y]++;
        }
    }
};


class Solution {
  public:
  
    bool isValid(int adjRow, int adjCol, int n, int m){
        return adjRow >=0 && adjCol >= 0 && adjRow < n && adjCol < m;
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<vector<int>> dir = {
            {0,1}, {1,0}, {-1,0},{0,-1}
        };
        
        DSU ds(m*n);
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // int vis[n][m];
        // memset(vis,0,sizeof vis);
        
        vector<int> ans;
        int count= 0;
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            vis[row][col] = 1;
            count++;
            
            for(auto side : dir){
                int adjRow = side[0]+row;
                int adjCol = side[1]+col;
                
                if(isValid(adjRow,adjCol,n,m)){
                    if(vis[adjRow][adjCol] == 1){
                        int nodeNum = row * m + col;
                        int adjNodeNum = adjRow * m + adjCol;
                        if(ds.find_par(nodeNum) != ds.find_par(adjNodeNum)){
                        ds.Union(nodeNum, adjNodeNum);
                        count--;
                       }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends