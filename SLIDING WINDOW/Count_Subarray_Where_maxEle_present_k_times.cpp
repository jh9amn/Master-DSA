#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        
        pair<int, long long> p;      // maxEle , freq

        for(int it : nums){
            p.first = max(p.first, it);
        }
        
        p.second = 0;
                
        long long count = 0;
        
        int n = nums.size();
        
        while( j < n){
            // calculation freq of max ele
            if(p.first == nums[j]) {
                p.second++;
            }
           // freq >= k then count no of subArray can make from j and by expanding of j 
           //  (n-j) gives no of subArray by maintaing the freq of maxElement
            while(p.second >= k){
                count += n-j;       // count subArrays possible n-j
                if(nums[i] == p.first) p.second--;
                i++;
            }
            
            j++;
        }
        return count;
    }
};


int main(){


}