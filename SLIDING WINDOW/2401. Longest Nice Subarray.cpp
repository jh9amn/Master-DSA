#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // int n = nums.size();
        // int ans = 1;
        // // TC = O(n^2)
        // for(int i=0; i<n; i++){
        //     int mask = nums[i];
        //     for(int j=i+1; j<n; j++) {
        //         if((mask & nums[j]) != 0) {
        //             break;
        //         }
        //         mask |= nums[j];        // store the set bit into mask for next & operation
        //         ans = max(ans, j-i+1);
        //     }
        // }
        // return ans;    


/* 
* Sliding Window
* remove any number from window use XOR of that number
* nums[i] & nums[j] == 0 when AND of their set bits give 0
* to calculate window:
        mask OR nums[j] give set bits of nums[j]
        again mask AND nums[j] != 0 -> means this is not valid window.
 */
        int i=0;
        int j=0;
        int ans = 1;
        int n = nums.size();
        int mask = 0;

        // TC = O(2n)
        while(j < n) {
            while((mask & nums[j]) != 0){     // keep shrinking
                mask ^= nums[i];    // remove that number fro the mask
                i++;
            }

            mask |= nums[j];                // add set bit of that numsber into mask
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};