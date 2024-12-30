#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1000001];
    int solve(int low, int high, int zero, int one, int len) {
        if(len > high) return 0;

        if(dp[len] != -1) return dp[len];

        int add = (solve(low, high, zero, one, len + zero)%mod
             + solve(low, high, zero, one, len + one)%mod)%mod;
        if(len >= low && len <= high) add += 1;
        return dp[len] = add % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof dp);
        return solve(low, high, zero, one, 0);
    }
};