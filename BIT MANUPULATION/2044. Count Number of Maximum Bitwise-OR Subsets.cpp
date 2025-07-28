#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        int n = nums.size();
        for(auto it : nums) {
            maxOR = maxOR | it;
        }

        vector<vector<int>> dp(n, vector<int> (maxOR + 1, -1));

        // T.C = 2^n
        function<int(int, int)> countSubsets = [&](int i, int targetXOR) -> int {
            if(i == n){
                return (targetXOR == maxOR) ? 1 : 0;
            }

            if(dp[i][targetXOR] != -1) return dp[i][targetXOR];

            // exclude
            int skip = countSubsets(i+1, targetXOR);
            // include
            int take = countSubsets(i+1, targetXOR | nums[i]);

            return dp[i][targetXOR] = skip + take;

        };

        return countSubsets(0, 0);
    }
};