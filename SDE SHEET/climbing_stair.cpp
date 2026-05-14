#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    /* Memoization */
    unordered_map<int, int> mp;
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        if(mp.count(n)) return mp[n];
        return mp[n] = climbStairs(n-1) + climbStairs(n-2);
    }


    /* Tabulation */
    int climbStairs(int n) {
        vector<int> dp(n+1);

        dp[0] = dp[1] = 1;

        for (int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    /*  Space Optimization */
    int climbStairs(int n) {
        int curr = 1, prev = 1;

        for (int i=2; i<=n; i++){
            int temp = curr + prev;
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};