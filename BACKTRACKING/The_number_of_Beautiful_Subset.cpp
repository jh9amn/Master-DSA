#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans;
    void Subsets(vector<int> &nums, int k, int i, map<int,int> &mp){
        if(i == nums.size()){
            ans++;
            return;
        }
        
        // not take
        Subsets(nums, k, i+1, mp);
        
        // take
        // mp should not have nums[i] + k and nums[i] - k
        if(!mp[nums[i] - k]  and !mp[nums[i] + k]){
            mp[nums[i]]++;
            Subsets(nums, k, i+1, mp);
            mp[nums[i]]--;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        ans = 0;
        map<int,int> mp;
        Subsets(nums, k, 0, mp);
        
        // remove empty subset
        return ans-1;
        
    }
};

int main(){}