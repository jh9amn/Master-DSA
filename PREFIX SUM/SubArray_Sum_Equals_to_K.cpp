#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // map for freq of prefix sum
        map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            // here calculating prefix sum as well as updating freq of prefix sum too
            prefixSum += nums[i];
            
            // if prefix sum - goal/k is present then count += its freq
            if(mp.find(prefixSum - k) != mp.end()){
                count += mp[prefixSum - k];
            }
            // updating map with prefixSum freq
            mp[prefixSum]++;
        }
        return count;
    }
};


int main(){

}