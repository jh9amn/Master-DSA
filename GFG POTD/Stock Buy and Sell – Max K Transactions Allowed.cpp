#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
  public:
    int n;
    int dp[1001][201][3];
    int solve(vector<int> &prices, int i, int k, int flag) {
        if(i == n || k == 0) return 0;
        
        int ans = INT_MIN;
        
        if(dp[i][k][flag] != -1) return dp[i][k][flag];
        
        // buy time
        if(flag == 0) {
           ans =  max(solve(prices, i+1, k, !flag) - prices[i],
                  solve(prices, i+1, k, flag));
        }   
        
        // sell time
        else {
            ans = max(solve(prices, i+1, k-1, !flag) + prices[i],
                  solve(prices, i+1, k, flag));
        }
        
        return dp[i][k][flag] = ans;
    }
    
    int maxProfit(vector<int>& prices, int k) {
        n = prices.size();
        memset(dp,-1, sizeof dp);
        return solve(prices, 0, k, 0);
    }
};