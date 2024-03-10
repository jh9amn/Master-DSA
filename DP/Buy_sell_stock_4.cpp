// leetcode 188

#include<bits/stdc++.h>
using namespace std;

int dp[1005][105][2];
    int f(vector<int> &prices, int i, int k, bool on){
        if(i == prices.size()) return 0;
        int ans = INT_MIN;
        if(dp[i][k][on] != -1) return dp[i][k][on];
        // nothing choice
        ans = max(ans,f(prices,i+1,k,on));
        // transcation is going on
        if(on == true) ans = max(ans, prices[i] + f(prices,i+1,k-1,false));
        // no ongoing transaction but has limit to buy
        else {
            if(k>0) ans = max(ans,f(prices,i+1,k,true) - prices[i]) ;
        }
        return dp[i][k][on] = ans;
        
    }


int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1, sizeof dp);
        return f(prices,0,k,false);  // initially no transaction so false..
    }