#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Top Down
    int dp[210][210];
    int f(vector<vector<int>> &v, int row, int col){
        if(row == v.size()-1) return v[row][col];  // last row or one row has same ans
        if(dp[row][col] != -1) return dp[row][col];
        // v[r][c] + min(down left ele, down right ele);
        return dp[row][col] = v[row][col] + min(f(v,row+1,col), f(v,row+1,col+1));
    }


    // Bottom Up
    int f(vector<vector<int>> &v){
        int n = v.size();
        // vector<vector<int>> dp(n+1,(vector<int> (n+1,-1)));
        // dp = v;
        // for(int j=0; j<v[n-1].size(); j++){
        //     dp[n-1][j] = v[n-1][j];
        // }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j < v[i].size(); j++){
                v[i][j] = v[i][j] + min(v[i+1][j],v[i+1][j+1]);
            }
        }
        return v[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // memset(dp,-1,sizeof dp);
        // return f(triangle,0,0);  
        return f(triangle); 
    }
};

int main(){
    
}