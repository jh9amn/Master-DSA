#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;          // {rem and count}
        
        for(int i=0; i<n; i++){
            prefixSum = (prefixSum + nums[i] % k + k);      // converting the positive
            int rem = prefixSum % k;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};

int main(){}