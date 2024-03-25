#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C = O(N)   S.C = O(1)
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
             
             int temp = abs(nums[i]);
             int idx = temp - 1;
             
             // agar < 0 hai to ans me push kro beacause visited again this  element
             if(nums[idx] < 0){
                 ans.push_back(temp);
             }
             // else mark as > 0 means (multiply with -1)
             else{
                nums[idx] *= -1;
             }
         }
        return ans;
    }
};



int main(){


}