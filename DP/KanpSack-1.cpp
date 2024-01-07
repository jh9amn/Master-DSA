#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<ll>> dp;
int f(vector<ll> &wts, vector<ll> &val, int i, int W){
    dp.resize(105, vector<ll> (100005, -1));
    int n = wts.size();
    if(i ==  n) return 0;
    if(dp[i][W] != -1) return dp[i][W];
    ll ans = INT_MIN;
    // Not  Pick
    ans = f(wts, val, i+1, W);
    // Pick 
    // (tatal Bag Limit) W - wts[i] and value at i will be added
    if(wts[i] <= W) {    // if bag has limit then pick
        ans = max(ans, f(wts, val, i+1, W-wts[i]) + val[i]);
    }
    return dp[i][W] = ans;
}


// Bottom Up
int fbu(vector<ll> &wts, vector<ll> &val, int W){
    dp.resize(105, vector<ll> (100005, 0));
    int n = wts.size();
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=W; j++){
            ll ans = INT_MIN;
            // Not Pick
            ans = max(ans,dp[i+1][j]);
            // Pick
            if(wts[i] <= j){
                ans = max(ans, val[i] + dp[i+1][j-wts[i]]);
            } 
            dp[i][j] = ans;
        }
    }
    return dp[0][W];
}


int main(){
    int n,W;   // n = weight arr and val arr size, W = bag Limit /  KanpSack limti
    cin>>n>>W;
    vector<ll> wts;
    vector<ll> val;
    for(int i=0; i<n; i++){
        int x, y;   // x is value of weight , y = value of val 
        cin>>x>>y;
        wts.push_back(x);
        val.push_back(y);
    }

    // cout<<f(wts,val,0,W)<<"\n";

    // Bottom Up
    cout<<fbu(wts, val, W)<<"\n";
    return 0;
}


/*
6 15
6 5
5 6
6 4
6 6
3 5
7 2
*/