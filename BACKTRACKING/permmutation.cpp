#include<bits/stdc++.h>
using namespace std;

// Approach 1:       T.C = n! * n   And S.C = O(1)
class Solution1 {
public:
    void f(int i, vector<int> &nums, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(nums);
        }
        
        // Using Swap way
        // t.c = n! * n && s.c = O(1)
        for(int idx = i; idx < nums.size(); idx++){
            swap(nums[i], nums[idx]);
            f(i+1,nums,ans);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f(0,nums,ans);
        return ans;
    }
};

// Approach 2:       T.C = n! * n   And S.C = n * n
class Solution2 {
public:
    void f(vector<int> &nums, vector<int> &v, vector<vector<int>> &ans,vector<int> &freq){
        int n = nums.size();
        if(v.size() == n) {
            ans.push_back(v);
            return;
        }
                   
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
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> freq (n,0);
        
        f(nums,v,ans,freq);
        return ans;
        
    }
};

int main(){

}