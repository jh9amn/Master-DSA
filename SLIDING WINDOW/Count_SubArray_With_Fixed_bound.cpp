#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C - O (N)   S.C - O(1)
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int mini = -1;
        int maxi = -1;
        int badi = -1;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK) badi = i;
            if(nums[i] == minK) mini = i;
            if(nums[i] == maxK) maxi = i;
            
            count += max(0 , min(mini, maxi) - badi);
        }
        return count;
        
    }
};



int main(){


}