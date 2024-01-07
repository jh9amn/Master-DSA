#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto &it : mp){
            int freq = it.second;
            if(freq == 1) return -1;
            ans += ceil((double) freq/3);
        }
        return ans;
    }
};


int main(){

}