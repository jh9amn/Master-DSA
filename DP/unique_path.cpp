#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    int dp[105][105];

    // int f(int i, int j){
    //     if( i == n || j == m) return 0;
    //     if( i == n-1 && j == m-1) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return dp[i][j] = f(i+1,j) + f(i,j+1);
    // }

    int fbu(int i, int j){
        memset(dp,0, sizeof dp);
        dp[n-1][m-1] = 1;
        for(int i=n-2; i>=0; i--){
            dp[i][m-1] = dp[i+1][m-1]; 
        }
        for(int j=m-2; j>=0; j--){
            dp[n-1][j] = dp[n-1][j+1]; 
        }

        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        } return dp[0][0];
    }
    int uniquePaths(int M, int N) {
        n = M;
        m = N;
        // memset(dp,-1,sizeof dp);
        // return f(0,0);

        // bottom up
        return fbu(0,0);
    }
};

int main(){
    
}