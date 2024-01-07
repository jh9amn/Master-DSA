#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define ll long long int 
    ll dp[105][105];
    // TOP DOWM
    // int f(vector<vector<int>> &v,int i, int j){
    //     int n = v.size(); 
    //     int m = v[0].size();
    //     // base case
    //     if(v[n-1][m-1] == 1) return 0;
    //     if(i < 0 || j < 0 || i >= n || j >= m) return 0;
    //     if(v[i][j] == 1) return  0;
    //     if(i == n-1 && j == m-1) return 1;
    //     if(dp[i][j] != -1 ) return dp[i][j];

    //     return  dp[i][j] = f(v,i,j+1)+f(v,i+1,j);
    // }

    // BOTTOM UP
    int fbu(vector<vector<int>> &v){
        memset(dp,0,sizeof dp);
        int n = v.size();
        int m = v[0].size();
        // base case
        if(v[n-1][m-1] == 1) return 0;
        dp[n-1][m-1] = 1; 
        for(int i=n-2; i>=0; i--){
            if(v[i][m-1] == 1) dp[i][m-1] = 0;
            else dp[i][m-1] = dp[i+1][m-1];
        }

        for(int j=m-2; j>=0; j--){
            if(v[n-1][j] == 1) dp[n-1][j] = 0;
            else dp[n-1][j] = dp[n-1][j+1];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                if(v[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {       
        // memset(dp,-1,sizeof dp);
        // return f(grid,0,0); 
        return fbu(grid);
    }
};

int main(){

}
