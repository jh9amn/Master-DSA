#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[205][205];
    // int f(vector<vector<int>> &v, int i, int j){
    //     int n = v.size();
    //     int m = v[0].size();
    //     if(i==n-1 && j == m-1) return v[n-1][m-1];
    //     if(i < 0 || j < 0 || i >= n || j >= m) return 1e9;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return dp[i][j] = v[i][j] + min(f(v,i+1,j), f(v,i,j+1));
    // }

    int fbu(vector<vector<int>> &v){
        memset(dp,0,sizeof dp);
        int n = v.size(); 
        int m = v[0].size();
        if(n >=1 || m >=1) dp[n-1][m-1] = v[n-1][m-1];
        for(int i=n-2; i>=0; i--){
            dp[i][m-1] = v[i][m-1] + dp[i+1][m-1];
        }
        for(int j=m-2; j>=0; j--){
            dp[n-1][j] = v[n-1][j] + dp[n-1][j+1];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                dp[i][j] = v[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        } return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& v) {
        // memset(dp,-1,sizeof dp);
        // return f(v,0,0);   

        // bottom up
        return fbu(v);
    }
};

int main(){
    
}