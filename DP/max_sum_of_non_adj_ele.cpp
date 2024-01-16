#include<bits/stdc++.h>
using namespace std;

// Momoiztion   Tc = O(n), Sc=O(n)
int fm( int n, vector<int> &v, vector<int> &dp){
    if( n == 0) return v[0];
    if( n < 0) return 0;

    if(dp[n] != -1) return dp[n];

    int pick = v[n] + fm(n-2, v, dp);
    int notPick = 0 + fm(n-1, v, dp);

    return dp[n] =  max(pick, notPick); 
}

// Tabulaion  Tc = O(n), Sc=O(n);
int ft( int n, vector<int> &v){
    vector<int> dp(n+1,0);
    dp[0] = v[0];

    for(int i=1; i<=n; i++){
        int pick = v[i];  
            if(i > 1 ) pick += dp[i-2];

        int notPick = 0 + dp[i-1];

        dp[i] = max(pick , notPick);
    }
    return dp[n];
}

// Space Optimization Of tabulation  
// Tc = O(n), Sc = O(1)
int fto( int n, vector<int> &v){
    int prev = v[0];           // dp[0]  = 0
    int prev2 = 0;          // dp[-1] = 0

    for(int i=1; i<=n; i++){
        int pick = v[i];  
            if(i >= 2 ) pick += prev2;

        int notPick = 0 + prev;

        int curr = max (pick , notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);    
    return fto(n-1,nums);
    
}

int main(){
    vector<int> v = {1,2,3,4,5};
    maximumNonAdjacentSum(v);
}