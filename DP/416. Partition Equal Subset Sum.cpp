#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int n;
    bool solve( vector<int> & nums, int mid, int i, vector<vector<int>> &dp) {
        if(mid == 0) return true;
        if(i >= n || mid < 0) return false;
        
        if(dp[i][mid] != -1) return dp[i][mid];

        int include = solve(nums, mid - nums[i], i+1, dp);
        int exclude = solve(nums, mid, i+1, dp);

        return dp[i][mid] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 == 1) return false;
        int mid = total/2;

        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (mid+1, -1));
        return solve(nums, mid, 0, dp);
    }
};