#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BS( int start, int end, vector<int>& v, int x){
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(v[mid] == x) return x;
            
            else if(v[mid] > x){
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
        }
         return -1;
    }
    
    
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == BS(i+1,nums.size() - 1, nums, nums[i])) return nums[i];
        }
        return -1;
    }
};


int main(){


}