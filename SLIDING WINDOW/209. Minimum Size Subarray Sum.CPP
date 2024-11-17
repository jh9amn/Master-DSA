#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int currWindowSum = 0;

        int left = 0, right = 0;

        while(right < nums.size()){
            currWindowSum += nums[right];

            while(currWindowSum >= target) {
                ans = min(ans, right - left + 1);
                currWindowSum -= nums[left];
                left++;
            }
            right++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};