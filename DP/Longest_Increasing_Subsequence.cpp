// https://leetcode.com/problems/longest-increasing-subsequence/submissions/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[2505][2505];
    // top down
    int f(vector<int> &v, int curr, int prev){
        if(curr == v.size() && prev == -1) return 1;
        if(curr == v.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        // Not Take
        int len = 0+f(v,curr+1,prev);
        // Take
        if(prev == -1 || v[curr] > v[prev]) {
            len = max(len,1+f(v,curr+1,curr));
        }
        return dp[curr][prev+1] = len;
    }


    // Tabulation / Bottom Up 
    int fbu(vector<int> &v){
        int n = v.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof dp);
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int len = 0 + dp[curr+1][prev+1];
                if(prev == -1 || v[curr] > v[prev]){
                    len = max(len, 1+ dp[curr+1][curr+1]);
                } 
                dp[curr][prev+1] = len;
            }
        }
        return dp[0][0];
    }


    // Printing LIS
    
    
    // Tabulation (bottom up)
    int fbu2(vector<int> &v){
        int maxi = 1;
        int n = v.size();
        vector<int>dp(n,1);
        for(int i=0; i<n; i++){
            for(int prev = 0; prev < i; prev++){   // TC = O(n^2)
                if(v[prev] < v[i]){
                    dp[i] = max(dp[i], 1+ dp[prev]);  // SC = O(n)
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }


// There is another way which is Patience sorting 
class Solution2 {
public:
    int f (vector<int> &nums,vector<int> &v){
        int n = nums.size();
        
        // Patience Sorting ,  T.C = (n log n)  , S.C = O(n)
        for(int i =0; i<n; i++){
             auto it = lower_bound(begin(v), end(v), nums[i]);  // just greater than or equal to nums[i]
            
            if(it == end(v)){
                v.push_back(nums[i]);  // greatest: so insert it
            }
            else{
                *it = nums[i];      // replace with nums[i]
            }
        }
        return v.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        return f(nums, v);
    }
};


    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        // return f(nums,0,-1);

        // tabulation
        return fbu(nums);
    }
};

int main(){

}