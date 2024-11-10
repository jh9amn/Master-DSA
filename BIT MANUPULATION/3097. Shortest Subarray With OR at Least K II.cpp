#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    void updateSetBits(int num, vector<int> &bitsCounts, int val){
        for(int i=0; i<32; i++){
            if((num >> i) & 1) bitsCounts[i] += val;    // increase and decrease set bits counts
        }
    }

    // converting binary to decimal of setBits index
    int getBitsValue(vector<int> bitCounts){
        int value = 0;
        for(int i=0; i<32; i++){
            if(bitCounts[i] > 0) {
                value = value | (1 << i);
            }
        }
        return value;
    }


    int minimumSubarrayLength(vector<int>& nums, int k) {
        // T.C = O(n^2) 
        // TLE
        // int n = nums.size();
        // int miniLen = INT_MAX;

        // for(int i=0; i<n; i++){
        //     int orValue = 0;
        //     for(int j=i; j<n; j++){
        //         orValue |= nums[j];
        //         if(orValue >= k) {
        //             miniLen = min(miniLen, j - i + 1);
        //             break;
        //         }
        //     }
        // }
        // return miniLen == INT_MAX ? -1 : miniLen;


        // Two Pointer Approach..
        vector<int> bitCounts(32,0);
        int miniLen = INT_MAX;

        int i = 0;
        int j = 0;
        int n = nums.size();

        while(j < n){
            updateSetBits(nums[j], bitCounts, 1);

            while(i <= j and getBitsValue(bitCounts) >= k) {
                miniLen = min(miniLen, j-i+1);
                updateSetBits(nums[i], bitCounts, -1);
                i++;
            }
            j++;
        }
        return miniLen == INT_MAX ? -1 : miniLen;
    }
};