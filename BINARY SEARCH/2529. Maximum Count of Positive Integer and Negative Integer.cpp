#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int neg_bs(vector<int> &nums, int low, int high) {
        int index = nums.size();
        while(low <= high) {
            int mid = (high + low) / 2;
            // small then find big
            if(nums[mid] < 0) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                index = mid;
            }
        }
        return index;
    }

    int pos_bs(vector<int> &nums, int low, int high) {
        int index = nums.size();
        while(low <= high) {
            int mid = (high + low) / 2;
            // big then find small
            if(nums[mid] > 0) {
                high = mid - 1;
                index = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return nums.size() - index;
    }


    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        return max(neg_bs(nums, 0, n-1), pos_bs(nums, 0, n-1));
    }
};