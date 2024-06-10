#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// assume path traversel of going and then coming as two person are started from same path but going in different direction but when they collapse then increase the cherry value just one time because at time of going the first persone already take path value and make that path value is now as ZERO.
    
//     int dp[50][50][50][50]; 
    
//     int solve(int r1, int c1, int r2, int c2, vector<vector<int>>& grid, int n){
//         if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
//             return INT_MIN;
//         }
        
//         // if both person reach destination...
//         if(r1 == n-1 and c1 == n-1) return grid[r1][c1];
//         if(r2 == n-1 and c2 == n-1) return grid[r2][c2];
        
//         if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
         
//         int cherry = 0;
//         if(r1 == r2 and c1 == c2 ){     // both person at same path then take one 1 time path value
//             cherry += grid[r1][c1];
//         }
//         else{                           // both are at different path then add both path value in cerry
//             cherry += grid[r1][c1] + grid[r2][c2];
//         }
        
//         int dd = solve(r1+1, c1, r2+1, c2, grid, n);
//         int rr = solve(r1, c1+1, r2, c2+1, grid, n);
//         int dr = solve(r1+1, c1, r2, c2+1, grid, n);
//         int rd = solve(r1, c1+1, r2+1, c2, grid, n);
        
//         cherry += max(max(dd,rr), max(dr,rd));
//         return dp[r1][c1][r2][c2] = cherry;
//     }
    
    
    
    
    int dp[50][50][50];
    int solve(int r1, int c1, int r2, vector<vector<int>>& grid, int n){
        int c2 = r1 + c1 - r2;
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
        
        // if both person reach destination...
        if(r1 == n-1 and c1 == n-1) return grid[r1][c1];
        if(r2 == n-1 and c2 == n-1) return grid[r2][c2];
        
        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
         
        int cherry = 0;
        if(r1 == r2 and c1 == c2 ){     // both person at same path then take one 1 time path value
            cherry += grid[r1][c1];
        }
        else{                           // both are at different path then add both path value in cerry
            cherry += grid[r1][c1] + grid[r2][c2];
        }
        
        int dd = solve(r1+1, c1, r2+1, grid, n);        // both person move down down
        int rr = solve(r1, c1+1, r2, grid, n);          // both person move right right
        int dr = solve(r1+1, c1, r2, grid, n);
        int rd = solve(r1, c1+1, r2+1, grid, n);
        
        cherry += max(max(dd,rr), max(dr,rd));
        return dp[r1][c1][r2] = cherry;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        int n = grid.size();
        return max(0, solve(0, 0, 0, grid, n));
    }
};

int main(){}