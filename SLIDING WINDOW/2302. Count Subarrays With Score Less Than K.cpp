#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;

        int i = 0;
        long long res = 0;
        for(int j=0; j<n; j++){
            ans += nums[j];

            while(i <= j && ans * (j - i + 1) >= k) {
                ans -= nums[i];
                i++;
            }
            
            res += (j - i + 1);
        }
        return res;
    }
};