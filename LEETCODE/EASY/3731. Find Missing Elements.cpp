#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums), end(nums));

        vector<int> ans;
        for(int i=1; i<nums.size(); i++){
            int x = nums[i-1] + 1;
            while(x != nums[i]){
                ans.push_back(x);
                x++;
            }
        }
        return ans;
    }
};
