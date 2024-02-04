// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // k = k%nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin()+k);
        // reverse(nums.begin()+k, nums.end());
        
        int n = nums.size();
        vector<int> v;
         k = k % n;
        if( n > k){
             for(int i = n-k; i<n; i++){
               v.push_back(nums[i]);
              }
            reverse(nums.begin(), nums.end());
            reverse(nums.begin()+k, nums.end());


            for(int i=0; i<v.size(); i++){
                nums[i] = v[i];
            }
        }
    }
};


int main(){

}