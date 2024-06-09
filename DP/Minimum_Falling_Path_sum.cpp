#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    
    // Memoization
    // T.C = O(n*n)     S.C = O(n*n)
    
    
//     int solve(vector<vector<int>> &matrix, int n , int i, int j, vector<vector<int>> &dp){
//         if(j >= n  || j < 0) return 1e9;
//         if(i == 0) return matrix[0][j];
        
//         if(dp[i][j] != 1e9) return dp[i][j];
                
//         int upleft = matrix[i][j] + solve(matrix, n, i-1, j-1, dp);
//         int upright = matrix[i][j] + solve(matrix, n, i-1, j+1, dp);
//         int up = matrix[i][j] + solve(matrix, n, i-1, j, dp);
        
//         return dp[i][j] = min(up, min(upleft, upright));
//     }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
//         vector<vector<int>> dp(n, vector<int> (n, 1e9));
        
//         int mini = 1e8;
//         for(int j=0; j<n; j++){
//             mini = min(mini, solve(matrix, n, n-1, j , dp));
//         }
//         return mini;
        
        
        
        
        
        // Tabulation
        
        // T.C = O(n*n) + O(n)          S.C = O(n*n)
//         vector<vector<int>> dp(n, vector<int> (n,0));
//         // Base case
//         for(int j=0; j<n; j++){
//             dp[0][j] = matrix[0][j];
//         }       
        
//         for(int i=1; i<n; i++){
//             for(int j=0; j<n; j++){   
//                 int up = matrix[i][j] + dp[i-1][j];
//                 int upleft = matrix[i][j];
//                 (j-1 >= 0) ? upleft += dp[i-1][j-1] : upleft = 1e8;
//                 int upright = matrix[i][j];
//                 (j+1 < n) ? upright += dp[i-1][j+1] : upright = 1e8;
                
//                 dp[i][j] = min(up, min(upleft, upright));
//             }
//         }
        
//         int mini = 1e9;
//         for(int j=0; j<n; j++){
//             mini = min(mini, dp[n-1][j]);
//         }
//         return mini;
        
        
        
        
        
        // Tabulation Space Optimization        S.C = O(n)
        vector<int> prev(n,0), curr(n,0);
        
        // Base case
        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }       
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){   
                int up = matrix[i][j] + prev[j];
                int upleft = matrix[i][j];
                (j-1 >= 0) ? upleft += prev[j-1] : upleft = 1e8;
                int upright = matrix[i][j];
                (j+1 < n) ? upright += prev[j+1] : upright = 1e8;
                
                curr[j] = min(up, min(upleft, upright));
            }
            prev = curr;
        }
        
        int mini = 1e9;
        for(int j=0; j<n; j++){
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};