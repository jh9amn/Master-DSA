#include<bits/stdc++.h>
using namespace std;
int main(){}


// int n;
// int dp[1006][1006];
// int pallindromic(int i, int j, string A) {
//     if(i > j) return 0;
//     if(i == j) return 1;
    
//     if(dp[i][j] != -1) return dp[i][j];
    
//     if(A[i] == A[j]) return 2 + pallindromic(i+1, j-1, A);
    
//     return dp[i][j] = max(pallindromic(i+1, j, A), pallindromic(i, j-1, A));
// }
// int Solution::solve(string A) {
//     n = A.size();
//     memset(dp, -1, sizeof dp);
//     return pallindromic(0, n-1, A);
// }

/***************************************************************************************************/

int dp[1006][1006];
int Solution::solve(string A) {
    int n = A.size();
    string B = A;
    reverse(B.begin(), B.end());
    
    memset(dp, 0, sizeof dp);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
