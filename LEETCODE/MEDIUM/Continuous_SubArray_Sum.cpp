#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;          // {remainder, index}
        
        mp[0] = -1;                         // agar first index value hai multiple of k hai so, don't count that
        
        int total = 0;
        
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
            
            int rem = total % k;
            
            if(!mp.count(rem)){             // present nahi hai
                mp[rem] = i;
            }
            else if(i - mp[rem] > 1) {      // present hai
                 return true;               // size > 1 return true
            }
        }   
        return false;
    }
};

int main(){

}