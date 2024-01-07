#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[25][25];
    // bool f(string s,string p, int i, int j){
    //     // if(i == s.size() && j == p.size()) return true;
    //     // if( (j < p.size() && p[j+1] != '*' && p[j] != '.' ) && i == s.size()) return false; 
    //     if( j == p.size()) return i == s.size();
    //     if(dp[i][j] != -1 ) return dp[i][j];
    //     if ( j+1 < p.size() and p[j+1] == '*'){
    //         return dp[i][j] = f(s,p,i,j+2) || ((i < s.size() && (s[i] == p[j] || p[j] == '.')) ? f(s,p,i+1,j) : false);
    //     }
    //     else if (i < s.size() && s[i] == p[j] || p[j] == '.'){
    //         return dp[i][j] = f(s,p,i+1,j+1);
    //     }
    //     else return dp[i][j] = false;
    // }
    bool fbu(string &s, string &p){
        int dp[25][25];
        memset(dp,0,sizeof dp);
        int n = s.size();
        int m = p.size();
        dp[n][m] = 1;
        for(int i=n; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if ( i < n && s[i] == p[j] || p[j] == '.') dp[i][j] = dp[i+1][j+1];
                else if ( j+1 < m && p[j+1] == '*') dp[i][j] = dp[i][j+2] || ((i < n && (p[j] =='.' || s[i] == p[j])) ? dp[i+1][j] : false);
                else dp[i][j] = false;
            }
        }
        return dp[0][0];
    }

    bool isMatch(string s, string p) {
        // memset(dp,-1,sizeof dp);
        // return f(s,p,0,0);   

        return fbu(s,p);
    }
};

int main(){

}