#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(i >= n || j >=  m) return 0;
        if(matrix[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = 1 + solve(i, j+1, n, m, matrix, dp);
        int down = 1 + solve(i+1, j, n, m, matrix, dp);
        int diagonal = 1 + solve(i+1, j+1, n, m, matrix, dp);

        return dp[i][j] = min({right, down, diagonal});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // need dp to store the maximum squale length from that idx
        vector<vector<int>> dp(n, vector<int> (m,-1));

        // to find sum of all maxi squares numbers
        int ans = 0;

        // go at every index of grid and calculate the max length of formed square possible
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans += solve(i, j, n, m, matrix, dp);
            }
        }

        return ans;
    }
};


// Approuch ...
/*
1) calculate maxi square formed from that index (i,j);
2) store it and add it then return as ans
*/