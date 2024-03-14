#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
            // 3rd Approach
        // USing Two Pointer Method or Sliding WIndow 
    // T.C = O(n)   S.C = O(1)
    int subArray(vector<int> &nums, int goal){
            int i = 0;
            int j = 0;
            int n = nums.size();
            int count = 0;
            int sum = 0;
            while( j < n){
                 sum += nums[j];
                // if sum > goal shrink window i++
                while(sum > goal && i < n){
                    sum -= nums[i];
                    i++;
                }
                
                // this will return number of subArray possible till j whose sum <= goal
                count += j - i + 1;
                j++;
             }
        return count;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Brute Force Tc = O(n*n)
        // int count = 0;
        // for(int i=0; i<nums.size(); i++){
        //     int sum = 0;
        //     for(int j=i; j<nums.size(); j++){
        //         sum += nums[j];
        //         if(sum == goal) count++;
        //     }
        // }
        

//         2nd Method 
//         map for freq of prefix sum
//         map<int, int> mp;
//         mp[0] = 1;
//         int prefixSum = 0;
//         int count = 0;
        
//         for(int i=0; i<nums.size(); i++){
//             // here calculating prefix sum as well as updating freq of prefix sum too
//             prefixSum += nums[i];
            
//             // if prefix sum - goal/k is present then count += its freq
//             if(mp.find(prefixSum - goal) != mp.end()){
//                 count += mp[prefixSum - goal];
//             }
//             // updating map with prefixSum freq
//             mp[prefixSum]++;
//         }
//         return count;
        
        
        // 3rd Method
        int i =  subArray(nums,goal);
        int j = subArray(nums, goal - 1);
        // cout<<i<<" "<<j<<endl;
        return (j < 0) ? i : i - j;
    }
};



int main(){


}