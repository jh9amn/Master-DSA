#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;

        int maxi = *max_element(begin(nums), end(nums));

        int count = 0 ;
        long long ans = 0;
        
        for(int j=0; j<n; j++){
            if(nums[j] == maxi){
                count++;
            }

            while(i <= j && count >= k){
                if(nums[i] == maxi) {
                    count--;
                }
                i++;
            }

            ans += i;
        }
        return ans;
    }
};