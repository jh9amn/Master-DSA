#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int minDiff = INT_MAX;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        // Two Pointer Approach 
        // T.C = O(nlog(n)) +  O(n^2)  
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;

            while(j < k) {
                int close = nums[i] + nums[j] + nums[k];
                int diff = abs(target - close);
                if(diff < minDiff){
                    ans = close;
                    minDiff = diff;
                }
                else if(close > target ) k--;
                else if(close < target) j++;
                else if(close == target) return ans;
            }
        }
        return ans;
    }
};