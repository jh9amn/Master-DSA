#include <bits/stdc++.h>
using namespace std;

// Leetcode  : https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/
class Solution {
public:
    int dir[8][2] = {
                        {-1,0},{-1,1,},{-1,-1},
                        {0,-1},{0,1},
                        {1,-1},{1,0},{1,1}
    };

    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] != 0) return -1;
        if(n==1) return 1;
        
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        distance[0][0] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        
        if(grid[0][0] != 0){
            return -1;
        }
        q.push({1,{0,0}});
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            if(n-1 == row && n-1 == col) return dis;
           
            for(auto it : dir){
                int newRow = it[0] + row;
                int newCol = it[1] + col;
    
                if((newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) &&
                   grid[newRow][newCol] == 0 && dis + 1 < distance[newRow][newCol]){
                    distance[newRow][newCol] = dis + 1;
                    q.push({distance[newRow][newCol],{newRow,newCol}});
                }
            }
        }
        return -1 ;
    }
};

// GFG 1..https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

class Solution {
  public:
  
   int dir[4][2] = {
                        {-1,0},
                {0,-1} ,        {0,1},
                        {1,0}
    };
    
    // in this ques , if the start node val is 0 .. so thare is no problem
       
       int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        
        int N = grid.size();
        int M = grid[0].size();
        
        int startRow = source.first;
        int startCol = source.second;
        
        if(startRow == destination.first && startCol == destination.second) return 0;
        
        vector<vector<int>> distance(N,vector<int>(M,1e9));
        distance[startRow][startCol] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{startRow,startCol}});
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(auto it : dir){
                int newRow = it[0] + row;
                int newCol = it[1] + col;
                
                if( newRow >= 0 && newRow < N && newCol >= 0 && newCol < M &&
                    grid[newRow][newCol] == 1 && dis + 1 < distance[newRow][newCol]){
                    distance[newRow][newCol] = dis + 1;
                    if(newRow == destination.first && newCol == destination.second) return dis + 1;
                    q.push({dis+1,{newRow,newCol}});
                }
            }
        }
        return -1 ;

    }
};

// GFG 2.. https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution {
  public:
  
    int dir[4][2] = {
                        {-1,0},
                {0,-1} ,        {0,1},
                        {1,0}
    };
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>> distance(N,vector<int>(M,1e9));
        distance[0][0] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        
        if(A[0][0] != 1) return -1;

        q.push({0,{0,0}});
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            if(row == X && col == Y) return dis;
            
            for(auto it : dir){
                int newRow = it[0] + row;
                int newCol = it[1] + col;
                
                if( newRow >= 0 && newRow < N && newCol >= 0 && newCol < M &&
                    A[newRow][newCol] == 1 && dis + 1 < distance[newRow][newCol]){
                    distance[newRow][newCol] = dis + 1;
                    q.push({dis+1,{newRow,newCol}});
                }
            }
        }
        // never reach that target index
        if(distance[X][Y] == 1e9) return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        // cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends