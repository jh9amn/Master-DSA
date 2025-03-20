#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
  public:
    int n;
    int dp[100001][3][3];
    int solve(vector<int> &prices, int i, int k, int sell) {
        if(k == 0 || i == n) return 0;
        
        if(dp[i][k][sell] != -1) return dp[i][k][sell];
        
        int ans = INT_MIN;
        
        // but time..
        if(sell == 0) {
            ans = max(solve(prices, i+1, k, true) - prices[i], solve(prices, i+1, k, false));
        }
        
        // sell time..
        else {
            ans = max(solve(prices, i+1, k-1, false) + prices[i], solve(prices, i+1, k, true));
        }
        
        return dp[i][k][sell] = ans;
    }
    int maxProfit(vector<int> &prices) {
        n = prices.size();
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, 2, false);
        
    }
};