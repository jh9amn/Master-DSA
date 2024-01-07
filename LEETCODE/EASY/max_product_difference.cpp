#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        int small = INT_MAX;
        int secondSmall = INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
            }else{  // koi   [ largest > ele  > secondlLargest ] but largest se chhota
                secondLargest = max(secondLargest, nums[i]);
            }
            if(nums[i] < small){
                secondSmall = small;
                small = nums[i];
            }else{ // koi [small < ele > secondSamll]  small se bda but secondSmall se choota tab
                secondSmall = min(secondSmall, nums[i]);
            }
        }
        
        return (largest * secondLargest) - (small * secondSmall);
    }
};
int main(){

}