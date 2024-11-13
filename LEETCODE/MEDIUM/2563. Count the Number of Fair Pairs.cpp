#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        // T.C = O(n^2)
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         int sum = nums[i] + nums[j];
        //         if(lower <= sum and sum <= upper) count++;
        //     }
        // }
        // return count;


         // Sort the array for easier range search
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            int min_val = lower - nums[i];
            int max_val = upper - nums[i];
            
            // Binary search to find valid range for nums[j] where i < j
            auto start = lower_bound(nums.begin() + i + 1, nums.end(), min_val);
            auto end = upper_bound(nums.begin() + i + 1, nums.end(), max_val);
            
            count += (end - start);
        }
        
        return count;

    }
};