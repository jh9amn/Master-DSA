#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i+=3){
            if(nums[i+2] - nums[i] > k) return {};
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ans;
    }
};

int main(){
    
}