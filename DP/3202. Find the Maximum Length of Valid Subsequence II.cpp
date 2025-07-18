#include<bits/stdc++.h>
using namespace std;
int main(){
}

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return n;

        function<int(int, int, int)> solve = [&](int i, int prev_idx, int
        prev_rem) -> int {
            if(i == n) return 0;

            // take
            int take = 0;
            if(prev_idx == -1) take = 1 + solve(i+1, i, -1);
            else {
                int curr_rem = (nums[i] + nums[prev_idx]) % k;
                if (prev_rem == -1 || curr_rem == prev_rem) take = 1 +
                solve(i+1, i, curr_rem);
            }
            // not take
            int not_take = solve(i+1, prev_idx, prev_rem);
           return max(take, not_take);
        };

        return solve(0, -1, -1);
    }
};

/**********************************************************************************************/

/* Using LIS Botton Up approach */
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k, vector<int> (n, 1));
        int maxiLen = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++) {
                int mod = (nums[i] + nums[j]) % k;  
                // mod = 0 or 1 
                dp[mod][i] = max(dp[mod][i], dp[mod][j] + 1);
                maxiLen = max(maxiLen, dp[mod][i]); 
            }
        }

        return maxiLen;
    }
};
