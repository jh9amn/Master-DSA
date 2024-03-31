#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C = O(n) , S.C = O(1)
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long count = 0;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int j = i;
            // just increase one step j+1 count the length of subarray
            while(j+1 < n and nums[j] != nums[j+1]){
                j++;
            }
            
            long long len = j - i + 1;
            // count the no of subarray possible in that range
            count += len*(len+1)/2;
            // then jump i to j 
            i = j;
        }
        return count;
    }
};


int main(){


}