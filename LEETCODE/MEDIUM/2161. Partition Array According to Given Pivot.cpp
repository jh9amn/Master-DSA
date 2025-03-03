#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);

        // i = 0 count < pivot ele
        // i = 1 count == pivot ele
        // i = 2 count > pivot ele
        int arr[3] = {0, 0, 0}; 

        for(int i=0; i<n; i++) {
            if(nums[i] < pivot) arr[0]++;
            else if(nums[i] == pivot) arr[1]++;
            else arr[2]++;
        }

        int i=0;    // pivot less index
        int j=arr[0];   // pivot index
        int k=arr[0] + arr[1];      // greater than pivot index

        for(int _i=0; _i<n; _i++) {
            if(nums[_i] < pivot) {
                ans[i++] = nums[_i];
            }
            else if(nums[_i] == pivot) {
                ans[j++] = nums[_i];
            }
            else ans[k++] = nums[_i];
        }
        return ans;
    }
};