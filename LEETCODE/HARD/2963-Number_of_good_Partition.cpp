#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int M = 1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        // storing the repeating ele ka last index
        unordered_map<int,int> Last_idx;  // ele -> last time present idx
        for(int i=0; i<nums.size(); i++){
            Last_idx[nums[i]] = i;
        }
        
        int i = 0;
        int j = 0;
        j = max( j , Last_idx[nums[0]]);
        
        int patition = 1;
        /*
        if we get the new partion then it will added to the (remaining partition * 2) ways
        and now partition  = partition * 2.. 
        */
        while(i < nums.size()){
            if(i > j){
                patition = (patition*2) % M;
                j++;
            }
            j = max(j, Last_idx[nums[i]]);
            i++;
        }
        return patition;
    }
};
int main(){

}