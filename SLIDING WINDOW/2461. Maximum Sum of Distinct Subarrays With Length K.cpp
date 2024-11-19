#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    // TLE
    // bool checkDupli(vector<int> nums, int i, int j){
    //     unordered_set<int> st;
    //     for(int idx = i; idx <= j; idx++){
    //         if(st.count(nums[idx])) return true;
    //         else st.insert(nums[idx]);
    //     }
    //     return false;
    // }
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxiSum = 0;
        int i=0; 
        int n = nums.size(); 
        int j = 0;
        long long currWindowSum = 0;

        unordered_set<int> st;
        while(j < n){

            // if seen the duplication then serink then no duplicate
            while(st.count(nums[j])){
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currWindowSum += nums[j];
            st.insert(nums[j]);

            if(j - i + 1 == k){
                // no duplicate 
                // if(!checkDupli(nums, i, j)){
                //     maxiSum = max(maxiSum, currWindowSum);
                //     currWindowSum -= nums[i];
                //     st.erase(nums[i]);
                //     i++;
                // }
                // else {
                //     currWindowSum -= nums[i];
                //     i++;
                // }

                maxiSum = max(maxiSum, currWindowSum);
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            
            j++;
        }
        return maxiSum;
    }
};