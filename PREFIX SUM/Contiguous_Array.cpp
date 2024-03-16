#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp{{0,-1}};
        int count = 0;
        int prefixSum = 0;
        for(int i=0; i<nums.size(); i++){
           // store prefix sum till at that index 
            prefixSum += nums[i] == 1 ? 1 : -1;
            
            if(mp.count(prefixSum) > 0) count = max(count, i - mp[prefixSum]);
            else mp[prefixSum] = i;
        }
        
        for(auto it : mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        return count;
    }
};


int main(){


}