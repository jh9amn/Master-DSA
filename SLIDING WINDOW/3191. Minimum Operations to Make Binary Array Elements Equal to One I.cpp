#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i=0; i<n-2; i++ ){
            if(nums[i] == 0) {
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = !nums[i+2];

                count++;
            }
        }

        // if any last two ele is zeros then not possible
        return nums[n-1] == 0 || nums[n-2] == 0 ? -1 : count;
    }
};