#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;

        // brute force
        // T.C = O(n^2)
        for(int i=0; i<=n-k; i++){
            bool isValid = true;

            for(int j=i+1; j<i+k; j++){
                if(nums[j] != nums[j-1] + 1) {      // not accending order consucative
                    isValid = false;
                    break;
                }
            }

            if(isValid) {
                ans.push_back(nums[i+k-1]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};