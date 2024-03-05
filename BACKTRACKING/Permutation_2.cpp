#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Method 1
    void f(vector<int> &nums, vector<int> &v, vector<vector<int>> &ans,vector<int> &freq){
        int n = nums.size();
        if(v.size() == n) {
            ans.push_back(v);
            return;
        }
        // T.C = n! * n + Unique and sort function    And S.C = n * n 
        for(int j=0; j<n; j++){
            if(freq[j] == 0){
                v.push_back(nums[j]);
                freq[j] = 1;
                f(nums,v,ans,freq);
                freq[j] = 0;
                v.pop_back();
            }
        }   
    }
    
    
    
    // Method 2
     void f2(int i, vector<int> &nums, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(nums);
        }
        
        // Using Swap way
        // t.c = n! * n + sort and Unique Function  && s.c = O(1)
        for(int idx = i; idx < nums.size(); idx++){
            swap(nums[i], nums[idx]);
            f2(i+1,nums,ans);
            swap(nums[i], nums[idx]);
        }
    }
    
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> ans;
//         vector<int> v;
//         vector<int> freq (n,0);
        
//         f(nums,v,ans,freq);
        
//         // Removing the Duplicate Elements from the 2D vector...
//         // Sort and bring the duplicates together
//         // use unique() to bring all the duplicates to end
//         // and get the ierator for the modified vector 
//          // Use erase method  to remove all the duplicates from the vector 
//         sort(ans.begin(), ans.end());
//         auto it = unique(ans.begin(), ans.end());
//         ans.erase(it, ans.end());
//         return ans;
        
        
        vector<vector<int>> ans;
        f2(0,nums,ans);
        // Removing the Duplicate Elements from the 2D vector...
        // Sort and bring the duplicates together
        // use unique() to bring all the duplicates to end
        // and get the ierator for the modified vector 
        // Use erase method  to remove all the duplicates from the vector 
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        return ans;
    }
};



int main(){

}