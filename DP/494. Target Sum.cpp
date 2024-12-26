#include<bits/stdc++.h>
using namespace std;
int main(){}


/*
- Time complexity: O(2^n)
- Space complexity: O(n)
*/
class Solution {
public:
    int totalWays = 0;
    void solve(vector<int> & nums, int idx, int target, int totalSum, int n){
        if(idx == n) {
            if(totalSum == target) {
                totalWays++;
                return;
            }
        }
        else {
            solve(nums, idx+1, target, nums[idx] + totalSum, n);
            solve(nums, idx+1, target, totalSum - nums[idx], n);
        }
    };


    int findTargetSumWays(vector<int>& nums, int target) {
        // vector<vector<int>> dp(20, vector<int> ())
        // int totalWays = 0;
        int n = nums.size();
        solve(nums, 0, target, 0, n);
        return totalWays;
    }
};


/*
- Time complexity: O(n * totalSum * 2)
- Space complexity: O(n * totalSum * 2)
*/
class Solution {
public:
    int solve(vector<int> & nums, int idx, int target, int currSum, int totalSum, vector<vector<int>> &dp){
        if(idx == nums.size()) return currSum == target ? 1 : 0;

        if(dp[idx][currSum + totalSum] != -1) return dp[idx][currSum + totalSum];
            
        int add = solve(nums, idx+1, target, nums[idx] + currSum, totalSum, dp);
        int sub = solve(nums, idx+1, target, currSum - nums[idx], totalSum, dp);

        dp[idx][currSum + totalSum] = add + sub;
        return dp[idx][currSum + totalSum];
    };


    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if (abs(target) > totalSum) {
            return 0;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (totalSum * 2 + 1, -1));
        return solve(nums, 0, target, 0, totalSum, dp);
    }
};