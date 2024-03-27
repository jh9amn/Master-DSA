#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // product < k
        if( k <= 1) return 0;
        
        int i = 0;
        int j = 0;
        
        int n = nums.size();
        int count = 0;
        int product = 1;
        
        while(j < n){
            product *= nums[j];
            // if( product >= k) i++;
            while(product >= k){
                product /= nums[i];
                i++;
            }
            
            // (j - i + 1 ) gives no. of subarray b/w i to j
            count += (j - i + 1);
            j++;

        }
        return count;
    }
};

int main(){


}