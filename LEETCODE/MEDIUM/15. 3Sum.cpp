#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        // Hash Map Approach...
        for(int i=0; i<n-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            unordered_set<int> st;
            for(int j = i+1; j<n; j++){
                int requiredValue = target - nums[j];
                if(st.count(requiredValue)){
                    ans.push_back({nums[i], requiredValue , nums[j]});
                    while(j+1 < n and nums[j] == nums[j+1]) j++;
                }
                st.insert(nums[j]);
            }
        }
        return ans;


        // Tow Pointer Approach...
        // for(int i=0; i<n-2; i++){
        //     if(i > 0 and nums[i] == nums[i-1]) continue;

        //     int j = i+1;    // left pointer
        //     int k = n-1;    // right pointer

        //     while(j < k){
        //         int target = nums[i] + nums[j] + nums[k];

        //         if(target == 0){
        //             ans.push_back({nums[i], nums[j], nums[k]});

        //             while(j < k and nums[j] == nums[j+1]) j++;
        //             while(j < k and nums[k] == nums[k-1]) k--;

        //             j++;
        //             k--;
        //         }
        //         else if(target < 0) {
        //             j++;
        //         }
        //         else k--;
        //     }
        // }
        // return ans;
    }
};