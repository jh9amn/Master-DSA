#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto i : nums){
            if(i>=1 && i<=n){
                mp[i]++;
            }
        }
        
        for(int i=1; i<=n; i++){
            if(mp[i] == 0) return i;
        }
        
        return n+1;
    }
};


int main(){

}