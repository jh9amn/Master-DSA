#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // T.C = O(n)   S.C = O(1)
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        
        int n = nums.size();
        
        int maxi = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            
            maxi = max( maxi, max(prefix, suffix));
            
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;      
        }
        return maxi;
    }
};


int main(){


}