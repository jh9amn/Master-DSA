#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//      Method 1  T.C = O(n*n)    TLE
//         int n = nums.size();
//         int maxi = INT_MIN;
//         for(int i=0; i<n; i++){
//             int sum = 0;
//             for(int j=i; j<n; j++){
//                 sum += nums[j];
//                 maxi = max(sum, maxi);

//             }
//         }
//         return maxi;
        

//          MEthod 2  (KADAN'S ALGORITHM)
//         T.C = O(n)
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            
            maxi = max(maxi, sum);
            
            if(sum < 0) sum = 0;
        }
        return maxi;
    }


    // if want to print the maximum subarray part then
    //     int maxi = INT_MIN;
    //     int sum = 0;
    //     int ans_start = 0;
    //     int ans_end = 0;
    //     int n = nums.size();

    //     for(int i=0; i<n; i++){
    //         int start = 0;
    //         sum += nums[i];
    //         if(sum >= 0)    start = i;
            
    //         if(sum > maxi){
    //             maxi = sum;
    //             ans_start = start;
    //             ans_end = i;
    //         }
            
    //         if(sum < 0) sum = 0;
    //     }
    //     return maxi;
    // }
};


int main(){


}