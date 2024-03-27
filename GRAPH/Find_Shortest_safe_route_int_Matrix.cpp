//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // T.C = O(n*m*4)  S.C = (n * m)
    bool isValid( int r, int c, int n, int m){
        return (r >= 0 and r < n and c >= 0 and c < m) ? true : false;
    }
    
    
    int findShortestPath(vector<vector<int>> &mat)
    {
       // first we need to mark all the landmine adjecents like top down left and right
       int n = mat.size(); 
       int m = mat[0].size();
       
       // direction array for four directions left right top  down
       int dr[4] = {-1, 0 , 1, 0};
       int dc[4] = {0, 1, 0 , -1};
       

       // all adjecents landmines directuion marked with 2 into mat
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(mat[i][j] == 0){
                   // if their is 0 element then iske up down left and right element ko bhi mark as 2
                   for(int k = 0; k<4; k++){
                       int nr = dr[k] + i;
                       int nc = dc[k] + j;
                       
                       if(isValid(nr, nc, n , m)){
                           mat[nr][nc] = 2;
                       }
                   }
               }
           }
       }
       
       
       // we use BFS to reach rigth most column
       // queue {dis,{i , j } }
       vector<vector<int>> vis(n, vector<int> (m,0));
       queue<pair<int, pair<int, int>> > q;
       
       // picking the start point from the mat except 0 for landmines and 2 for adjecent of landmines marks
       for(int i=0; i<n; i++){
           if(mat[i][0] == 1){
               q.push({1,{i,0}});    // where 1 =  distance ,  i =  row, 0 = column
           }
       }
       
       
       while(!q.empty()){
           auto it = q.front();
           q.pop();
           
           int dis = it.first;
           int row = it.second.first;
           int col = it.second.second;
           
           // if reached the last col then return the distance of it...
           if(col == m - 1) return dis;
           vis[row][col] = 1;
           
           
           for(int k=0; k<4; k++){
               int nr = dr[k] + row;
               int nc = dc[k] + col;
               
               if(isValid(nr , nc, n , m) && mat[nr][nc] == 1 && vis[nr][nc] == 0) {
                   q.push({dis + 1, {nr, nc}});
               }
           }
       }
       return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends