#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<vector<int>> res;
        
        for(int i=0; i<nums.size(); i++){
            int freq = mp[nums[i]];
            if(freq == res.size()){     // if freq == res.size ke then nya row aloat kar do
                res.push_back({}); 
            }
            res[freq].push_back(nums[i]);
            mp[nums[i]]++;
        }
        
        return res;
    }
};

int main(){

}