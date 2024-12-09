#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> t(n,0);
        int cumulativeSum = 0;
        for(int i=1; i<n; i++){
            int a = nums[i-1] % 2;
            int b = nums[i] % 2;
            if(a == b) {
                cumulativeSum++;
            }
            t[i] = cumulativeSum;
        }
        
        vector<bool> ans;
        for(auto it : queries){
            if(t[it[1]] - t[it[0]] != 0) ans.push_back(false); 
            else ans.push_back(true);
        }
        return ans;
    }
};