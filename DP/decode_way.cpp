#include<bits/stdc++.h>
using namespace std;
int dp[110];
    int f(string &s ,int i){
        // base case 
        if( i == s.size()) return 1;  // one digit = one char
        if(dp[i] != 0) return dp[i];
        int ans = 0;
        if(s[i] != '0') ans += f(s,i+1);
        // if(1str char ==1  or 2 ans 2nd char 0 -> 6) then
        if( i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
        ans += f(s,i+2);
        return dp[i] = ans;
    }
int numDecodings(string s) {
        memset(dp,0,sizeof dp);
        return f(s,0);  
}
int main(){

}

// https://leetcode.com/problems/decode-ways/