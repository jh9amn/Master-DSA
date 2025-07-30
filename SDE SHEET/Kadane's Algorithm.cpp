#include<bits/stdc++.h>
using namespace std;
int main(){}

/* 53. Maximum Subarray 
https://leetcode.com/problems/maximum-subarray/description/
*/

// Recursive Approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        function<void(int, int)> solve = [&] (int i, int currSum){
            if(i >= n) return;
            
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(currSum, maxSum);

            solve(i+1, currSum);
        };

        solve(0, 0);
        return maxSum;
    }
};

// Memoized with 1D Array
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        vector<int> dp(n, INT_MIN);
        function<int(int)> solve = [&] (int i) -> int{
            if(i >= n) return 0;
            
            if(dp[i] != INT_MIN) return dp[i];

            dp[i] = max(nums[i], nums[i] + solve(i+1));

            return dp[i];
        };

        for(int i=0; i<n; i++) {
            maxSum = max(maxSum, solve(i));
        }
        return maxSum;
    }
};


/** Kadane's Algorithm  **/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int currSum = nums[0];
        for(int i=1; i<n; i++){
            // nums[i] to start fresh
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};


// Store start and end of subArray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int currSum = nums[0];
        int start = 0;
        int end = 0;
        int tempStart = 0;

        for(int i=1; i<n; i++) {
            // fresh start of subArray
            if(nums[i] > currSum + nums[i]) {
                currSum = nums[i];
                tempStart = i;
            }
            else {
                currSum = currSum + nums[i];
            }

            // start and end of subArray
            if(maxSum < currSum) {
                maxSum = currSum;
                start = tempStart;
                end = i;
            }
        }

        return maxSum;
    }
};