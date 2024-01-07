#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1; // first two are not equal then count++ and unique element are two
        for(int i=1; i<nums.size(); i++){
            // place the unique element at the nums ke count index
            if(nums[i] != nums[i-1]) nums[count++] = nums[i];
        }
        return count;    
    }
};

int main(){

}