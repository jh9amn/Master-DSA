#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        function<long long(int)> memo = [&](int i) {
            if(i >= n) return 0LL;

            if(dp[i] != -1) return dp[i];

            long long take = questions[i][0] + memo(i + questions[i][1] + 1);
            long long not_take = memo(i+1);

            return dp[i] = max(take, not_take);
        };

        // return memo(0);

        // top down
        for(int i=n-1; i>=0; i--) {
            int prev_choice = i + questions[i][1] + 1;
            long long take = questions[i][0] + (prev_choice < n ? dp[prev_choice] : 0);
            long long not_take = i+1 < n ? dp[i+1] : 0;

            dp[i] = max(take, not_take);
        }

        return dp[0];
    }
};