#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;
    int dp[101][101][2];
    int aliceMax(vector<int>& piles, bool Alice, int i, int M) {
        if(i >= N) return 0;

        if(dp[i][M][Alice] != -1) return dp[i][M][Alice];

        int res = Alice ? 0 : INT_MAX;
        int turnTotal = 0;

        for(int X=1; X <= 2*M and i+X <= N; X++){

            turnTotal += piles[i+X-1];
            int newM = max(M, X);

            if(Alice){
                res = max(res , turnTotal + aliceMax(piles, false, i+X, newM));
            }
            else{
                res =  min(res, aliceMax(piles, true, i+X, newM));
            }
        }

        return dp[i][M][Alice] = res;
    }
    int stoneGameII(vector<int>& piles) {
        N = piles.size();
        memset(dp, -1, sizeof(dp));
        return aliceMax(piles, true, 0, 1); // start with alice
    }
};
