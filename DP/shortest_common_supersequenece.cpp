// https://leetcode.com/problems/shortest-common-supersequence/
#include<bits/stdc++.h>
using namespace std;
string fbu(string &s, string &t, int x, int y){
    vector<vector<int>> dp(x+1,vector<int>(y+1,0));
    for(int i=0; i<=x; i++) dp[i][0] = 0;
    for(int j=0; j<=y; j++) dp[0][j] = 0;
    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    // Shortest common supersequence
    string ans = "";
    int i = x; 
    int j = y;
    while(i != 0 && j != 0){
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans += s[i-1];
            i--;
        }
        else{
            ans += t[j-1];
            j--;
        }
    }
    while(i != 0){
        ans += s[i-1];
        i--;
    }
    while(j != 0){
        ans += t[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
    
string shortestCommonSupersequence(string str1, string str2) {
    int x = str1.size();
    int y = str2.size();
    return fbu(str1,str2,x,y);  
}
int main(){
    string str1 ="abac";
    string str2 = "cab";
    cout<<shortestCommonSupersequence(str1,str2);
}