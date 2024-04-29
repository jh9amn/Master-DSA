#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total = 0;
        for(auto it : nums){
            total ^= it;
        }
        
        // Counting Number of Bit Difference..
        int diff = (total ^ k);
        return __builtin_popcount(diff);
    }
};


int main(){

}