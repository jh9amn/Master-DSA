#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
  public:
    int n;
    bool solve(vector<int> &arr, int sum, int i, vector<vector<int>> &dp) {
        if(sum == 0) return true;
        if(i >= n || sum < 0) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        // if(arr[i] > sum) return solve(arr, sum, i+1);
        // return solve(arr,sum - arr[i], i+1) || solve(arr, sum, i+1);
        
        bool take = solve(arr, sum - arr[i], i+1, dp);
        bool untake = solve(arr, sum, i+1, dp);
        
        return dp[i][sum] = take || untake;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return solve(arr, sum, 0, dp);
    }
};