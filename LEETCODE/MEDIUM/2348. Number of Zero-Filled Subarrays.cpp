#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> temp(n,0);
        if(nums[0] == 0) temp[0] = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] == 0) {
                temp[i] = 1 + temp[i-1];
            } 
        }

        for(auto it : temp) {
            ans += it;
        }

        return ans;
    }
};

/*
0 0 0 0
1 2 6 10
*/