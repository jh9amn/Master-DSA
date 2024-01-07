// https://leetcode.com/problems/subsets/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void storeSubset(vector<int>& nums,int i,vector<int> v, vector<vector<int>> &res){
        if( i == nums.size() ) {
            res.push_back(v);
            return;
        }
        storeSubset(nums,i+1,v,res);
        v.push_back(nums[i]);
        storeSubset(nums,i+1,v,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> res;
        storeSubset(nums,0,v,res);
        return res;
    }
};
int main(){

}