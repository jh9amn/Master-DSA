#include<bits/stdc++.h>
using namespace std;
int main(){
}

class Solution {
public:
    int dp[2501][2502];
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof dp);

        function<int(int, int)> solve = [&] (int i, int prev_idx) -> int {
            if(i == n) return 0;
            if(dp[i][prev_idx + 1] != -1) return dp[i][prev_idx + 1];

            int take = 0;
            int skip = 0;
              if (prev_idx == -1 || nums[i] > nums[prev_idx]) {
                take = 1 + solve(i + 1, i);
            }
            skip = solve(i+1, prev_idx);

            return dp[i][prev_idx + 1] = max(take, skip);
        };

        return solve(0, -1);
    }
};

/************************************************************************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));

        auto solve = [&] (int i, int prev_idx, auto &&self) {
            if(i == n) return 0;
            if(dp[i][prev_idx+1] != -1) return dp[i][prev_idx+1];

            int take = 0;
            int skip = 0;
              if (prev_idx == -1 || nums[i] > nums[prev_idx]) {
                take = 1 + self(i + 1, i, self);
            }
            skip = self(i+1, prev_idx, self);

            return dp[i][prev_idx+1]= max(take, skip);
        };

        return solve(0, -1, solve);
    }
};

/************************************************************************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int prev=i-1; prev >= -1; prev--) {
                int take = 0;
                if(prev == -1 || nums[i] > nums[prev]) {
                   take = 1 + dp[i+1][i+1];     // prev = i + 1
                }
                int skip = dp[i+1][prev+1];
                dp[i][prev + 1] = max(take, skip);
            }
        }
        return dp[0][0];    // Starting with i=0, prev=-1 → mapped to prev+1 = 0
    }
};

/************************************************************************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);
        int maxi = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                maxi = max(dp[i], maxi);
            }
        }
        return maxi;    // Starting with i=0, prev=-1 → mapped to prev+1 = 0
    }
};
