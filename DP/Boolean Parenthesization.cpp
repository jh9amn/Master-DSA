#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
  public:
    int countWays(string &s) {
        int n = s.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
        
        function<int(int, int, bool)> solve = [&](int i, int j, bool isTrue) -> int {
            if(i > j) return 0;
            if(i == j) {
                if(isTrue) return s[i] == 'T' ? 1 : 0;
                else return s[i] == 'F' ? 1 : 0;
            }
            
            if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
            
            int ways = 0;
            
            for(int k=i+1;  k <= j-1; k+=2) {
                int LT = solve(i, k-1, true);
                int LF = solve(i, k-1, false);
                
                int RT = solve(k+1, j, true);
                int RF = solve(k+1, j, false);
                
                if(s[k] == '&') {
                    if(isTrue) ways += (LT * RT);
                    else ways += (LF * RT) + (LT * RF) + (LF * RF);
                }
                
                
                else if(s[k] == '|') {
                    if(isTrue) ways += (LF * RT) + (LT * RF) + (LT * RT);
                    else ways += (LF * RF);
                }
                
                else {
                    if(isTrue) ways += (LF * RT) + (LT * RF);
                    else ways += (LT * RT) + (LF * RF);
                }
            }
            return dp[i][j][isTrue] = ways;
        };
        
        return solve(0, n-1, true);     
    }
};
