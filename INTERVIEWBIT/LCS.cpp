#include<bits/stdc++.h>
using namespace std;
int main(){}

// Top Down
int n;
int m;
int dp[1006][1006];
int LCS(int i, int j, string A, string B) {
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(A[i] == B[j]) return 1 + LCS(i+1, j+1, A, B);
    return dp[i][j] = max(LCS(i+1, j, A, B), LCS(i, j+1, A, B));
}

int Solution::solve(string A, string B) {
    memset(dp, -1, sizeof dp);
    n = A.size();
    m = B.size();
    return LCS(0, 0, A, B);
}

/******************************************************************************/
// bottom up

int Solution::solve(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    
    vector<vector<int>> dp(n+1, vector<int> (m+1,0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
}
