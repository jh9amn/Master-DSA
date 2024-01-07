#include<bits/stdc++.h>
using namespace std;
    int dp[1005][1005];
    int f(string &s, string &t, int i, int j){
        if(j == -1) return 1;  // all element matching finished
        if(i == -1) return 0;  // element matching remaining but i become -1
        if(dp[i][j] != -1) return dp[i][j];
        // if match then (sum of take or not take)
        if(s[i] == t[j]) return dp[i][j] = f(s,t,i-1,j-1) + f(s,t,i-1,j);
        // if not match then i-- (check another element)
        else return dp[i][j] = f(s,t,i-1,j);
    }   


    // BOTTOM UP(TABULATION)
    int fbu(string &s, string &t){
        // base case(1 base indexing)
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1,vector<double> (m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int j=1; j<=m; j++) dp[0][j] = 0;  // for j=0 then dp[i][j] = 1
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return int(dp[n][m]);
    }
    int numDistinct(string s, string t) {
         // top down
        memset(dp,-1,sizeof dp);
        // return f( s, t, s.size()-1, t.size()-1);  

         // bottom up
        return fbu(s,t); 
    }
    int main(){

    }