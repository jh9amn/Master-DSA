#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // top down
    int dp[1005][1005];
    int f(string &s, string &t, int i, int j){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 1+f( s, t, i-1, j-1);
        return dp[i][j] = max(f(s,t,i-1,j) , f(s,t,i,j-1));
    }

    //bottom up
    int fbu(string &s, string &t, int x, int y){
        vector<vector<int>> DP(x+1,vector<int>(y+1,0));
        for(int i=0; i<=x; i++) DP[i][0] = 0;
        for(int j=0; j<=y; j++) DP[0][j] = 0;
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                if(s[i-1] == t[j-1]) DP[i][j] = 1 + DP[i-1][j-1];
                else DP[i][j] = max(DP[i-1][j] , DP[i][j-1]);
            }
        }return DP[x][y];
    }
    
    
    int longestPalindromeSubseq(string s) {
        int x = s.size();
        string t = s;
        // if reverse of string s and string s both LCS is the longest Palindromic subsequene
        reverse(t.begin(), t.end());
        return fbu(s,t,x,x);
    }
};


int main(){

}