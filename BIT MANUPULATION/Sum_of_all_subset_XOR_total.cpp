#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    // Approach 1:
    //  T.C = O(2^n * L)  // L for removing and adding elememt (iterating)
    //  S.C = O(2^n * L)
    void findSubsets(vector<int> nums, vector<vector<int>> &subsets, vector<int> &v, int i){
        if(i == nums.size()){
            subsets.push_back(v);
            return;
        }
        
        // ek baar add karke
        v.push_back(nums[i]);
        findSubsets(nums, subsets, v, i+1);
        // ek baar remove karka
        v.pop_back();
        findSubsets(nums, subsets, v, i+1);
    }
    
    
    // Approach 2 - Modified Space of Approach 1
    // T.C = O(2^n)  no iteration On array need
    // S.C = O(n)    depth of recurtion tree
     int findSubsetsOptimized(vector<int> nums,int i, int XOR){
        if(i == nums.size()){
            return XOR;
        }
        
        int take = findSubsetsOptimized(nums, i+1, nums[i] ^ XOR);
        int notTake = findSubsetsOptimized(nums, i+1, XOR);
         
         return take + notTake;
    }
    
    int subsetXORSum(vector<int>& nums) {
        // vector<vector<int>> subsets;
        // vector<int> v;        
        // findSubsets(nums, subsets, v, 0);
        // int ans = 0;
        // for(vector<int> &subset : subsets){
        //     int XOR = 0;
        //     for(int &val : subset){
        //         XOR ^= val;
        //     }
        //     ans += XOR;
        // }
        // return ans;
        
        
        return findSubsetsOptimized(nums, 0, 0);
    }
};
int main(){}