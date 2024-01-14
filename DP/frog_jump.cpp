#include <bits/stdc++.h> 
using namespace std;

// Memoization..
int f(int i, vector<int> &h, vector<int> &dp){
    if( i==0) return 0;

    if(dp[i] != -1) return dp[i];

    int left = abs(h[i-1]-h[i]) + f(i-1,h, dp);
    int right = INT_MAX;
    if(i > 1)
    right = abs(h[i-2]-h[i]) + f(i-2,h, dp);
    return dp[i] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    return f(n-1,heights, dp);
}


// Tabulation..
int f(int i, vector<int> &h){
    int n = h.size();
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int jump = abs(h[i] - h[i-1]) + dp[i-1];
        int longJump = INT_MAX;
        if(i > 1)
        longJump = abs(h[i] - h[i-2]) + dp[i-2];
        
        dp[i] = min (jump, longJump);
    }
    return dp[n-1];
}

int frogJump(int n, vector<int> &heights)
{
    return f(0,heights);
}

int main (){

}