#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subArrays(vector<int>& nums, int k) {
        map<int,int> mp; // ele , freq
        
        int i=0, j=0;
        int count = 0;
        int n = nums.size();
        
        while( j < n){
            mp[nums[j]]++;
           
            while(mp.size() > k and i <= j){ 
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            // k <= SubArrays
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // SubArray less than equal to K - less than K
        int ans = subArrays(nums, k) - subArrays(nums, k - 1);
        return ans;
    }
};



int main(){


}