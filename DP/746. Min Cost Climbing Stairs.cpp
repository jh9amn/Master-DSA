#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int solve(vector<int> &cost, int i, vector<int> &dp){
        int n = cost.size();
        if(i >= n) return 0;

        if(i == n-1 || i == n-2) return dp[i] = cost[i];
        if(dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(solve(cost, i+1, dp), solve(cost, i+2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};