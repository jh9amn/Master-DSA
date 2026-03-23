/*
NOTE: 
** If finding Kth largest then keep all greater ele to left of pivot

*/


class Solution {
public:
    int partition(int L, int R, vector<int> &nums){
        int i = L+1;
        int j = R;
        int p = nums[L];

        while(i <= j){
            if(nums[i] < p and nums[j] > p){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            // nums[i] is at right place
            if(nums[i] >= p){
                i++;
            }
            if(nums[j] <= p){
                j--;
            }
        }
        swap(nums[L], nums[j]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int L = 0;
        int R = size - 1;

        int pivot_idx = 0;

        while(true){

            pivot_idx = partition(L, R, nums);

            if(pivot_idx == k-1){
                break;
            }
            else if(pivot_idx > k-1){
                R = pivot_idx-1;
            }
            else{
                L = pivot_idx+1;
            }
        }
        return nums[pivot_idx];
    }
};

#include<bits/stdc++.h>
using namespace std;
int main(){}