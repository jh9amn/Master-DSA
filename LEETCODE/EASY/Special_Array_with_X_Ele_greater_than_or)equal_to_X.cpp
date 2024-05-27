#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        
        while(x <= n){
            int count = 0;
            
            for(int i=0; i<n; i++){
                if(nums[i] >=x){
                    count++;
                }
            }
            
            if(count == x){
                return x;
            }
            x++;
        }
        return -1;
    }
};

int main(){}