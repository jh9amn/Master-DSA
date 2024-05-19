#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int count = 0;
        long long temp = INT_MAX;
        
        for(auto it : nums){
            if( (it^k) > it){
                sum += it ^ k;
                temp = min(temp, (long long) (it^k) - it);
                count++;
            }
            else {
                sum += it;
                temp = min(temp, (long long) it - (it^k));
            }
        }
        if(count % 2 == 0) return sum;
        return sum - temp;
        
    }
};


int main(){

}