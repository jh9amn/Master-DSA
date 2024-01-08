#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

// https://www.codingninjas.com/studio/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=PROBLEM
// int mod = 1000000007;
// int N;
// int dp[N+1][N+1][2];

long long f(int i, int j, int isTrue, string &exp,
 vector<vector<vector<ll>>> &dp){
    // Base Case :
    if(i > j) return 0;
    if(i == j) {
        if(isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    ll ways = 0;

    for(int idx = i+1; idx <= j-1; idx += 2) {
        int LT = f(i,idx - 1,1,exp,dp) % mod ;
        int RT = f(idx + 1,j,1,exp,dp) % mod;
        int RF = f(idx + 1,j,0,exp,dp) % mod;
        int LF = f(i,idx - 1,0,exp,dp) % mod;

        if(exp[idx] == '&') {
            if(isTrue) ways = (ways + (LT * RT)%mod)%mod;
            else ways = (ways + (RF * LF)%mod + (RF * LT)%mod + (LF * RT)%mod)%mod; 
        }

        else if(exp[idx] == '|') {
            if(isTrue) ways = (ways + (LT * RF)%mod + (RT * LF)%mod + (LT * RT)%mod)%mod;
            else ways = (ways + (LF * RF)%mod)%mod;
        }

        else {
            if(isTrue) ways = (ways + (LF * RT)%mod + (RF * LT)%mod)%mod;
            else ways = (ways + (LT * RT)%mod + (RF * LF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    int n = exp.size();
    int isTrue = 1;
    // memset(dp, -1 , sizeof dp);
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>> (n+1,vector<ll>(2,-1)));
    return f(0,n- 1,1,exp,dp);
}


 int main(){

 }