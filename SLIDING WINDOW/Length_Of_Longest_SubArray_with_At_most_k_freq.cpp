#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C = O(N)    S.C = O(N)
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        
        int i = 0;
        int j = 0;
        
        int n = nums.size();
        
        int maxSize  = 0;
        
        while( j < n){
            mp[nums[j]]++;
            
            while( i < j and mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
            // j - i + 1  gives size of subarray
            maxSize = max(maxSize , j - i + 1);
            j++;
        }
        return maxSize;
    }
};


int main(){



}