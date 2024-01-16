#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std; 
// memoization
int fm(vector<int> &h,int i, int k){
    if( i == 0) return 0;

    int minStep = INT_MAX;

    for(int j=1; j<=k; j++){
        if(i - j > 0){
            int jump = fm(h,i-j,k) + abs(h[i]- h[i-j]);
            minStep = min(minStep, jump);
        }
    }

    return minStep;
}

// Tabulation..
int ft(vector<int> &h,int n, int k){
    int dp[n];
    dp[0] = 0;

// here, we can optimized space using k size list but when the size of k == n then 
// at that senerio we need a n size list which is equal again that without space optimized..
    for(int i=1; i<n; i++){
        int maxStep = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j >= 0){
                int jump = dp[i-1] + abs(h[i] - h[i-j]);
                maxStep = min(maxStep, jump);
            } 
        }
        dp[i] = maxStep; 
    }
    return dp[n-1];
}


int main(){
    vector<int> h = {1,2,3,4};
    int n = h.size();
    int k = 4;
    fm(h,n-1,k);
}