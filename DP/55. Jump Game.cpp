#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    // Memoized Approach
    bool solve(vector<int> &nums,  int i, int n, vector<int> &dp) {
        if(i >= n-1) return true;

        if(dp[i] != -1) return dp[i];

        int num = nums[i];
        for(int k = 1; k <= num; k++) {
            if(solve(nums, i + k, n, dp)) {
                dp[i + k] = true;
                return true;
            }
        }
        dp[i] = false;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);        
        return solve(nums, 0, n, dp);
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        /* Linear Approach */
        int farthest = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > farthest) {
                return false; // nums[i] == 0 return false
            }
            farthest = max(farthest, i + nums[i]); // if farthest value > n-1 then when can take less val
            if (farthest >= nums.size() - 1) {
                return true; // If the farthest index reaches or exceeds the last index
            }
        }
        return false; 
    }
};