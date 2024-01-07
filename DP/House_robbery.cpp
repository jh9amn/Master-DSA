// https://leetcode.com/problems/house-robber/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;

    // top Down
    int f(vector<int> &v , int i){
        if(v.size()-1 == i) return v[i];  // only one house then
        if(v.size()-2 == i) return max(v[i], v[i+1]);  //  only two house the
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(v[i]+f(v,i+2), 0+f(v,i+1));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        return f(nums,0);
    }

    // Bottom Up..

    int fbu(vector<int> &v){
        int n = v.size();
        if(n == 1) return v[0];

        dp.clear();
        dp.resize(n);

        // base case
        dp[n-1] = v[n-1];
        dp[n-2] = max(v[n-1], v[n-2]);

        for(int i=n-3; i>=0; i--){
            dp[i] = max(v[i]+dp[i+2], 0+dp[i+1]);
        }
        return dp[0];
    }
};
int main(){
    Solution s;
    vector<int> v = {1,2,3,1};
    cout<<s.rob(v);
}