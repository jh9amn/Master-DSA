#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        if(nums.size() == 1 && nums[0] == 0) return ;
        
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            // if we found 0 then count++
            if(nums[i] == 0) {
                count++;
            }
            
            // else like count  = 2 then
            // nums[i- 2] = temp, which is not zero and nums[i-1] remain 0 (no change in it) and we make nums[i] = 0
            else if(count > 0){
                int temp = nums[i];
                nums[i] = 0;
                nums[i - count] = temp;
            }
        }
        
    }
};


int main(){

}