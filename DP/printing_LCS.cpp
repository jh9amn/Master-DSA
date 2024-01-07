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
// printing LCS
int len = dp[x][y];
string ans = "";
for(int i=0; i<len; i++) ans += '#';
int i=x; 
int j=y;
int idx = len-1;
    while(i>0 && j>0){
        if(s[i-1] == t[j-1]) {
            ans[idx] = s[i-1];
            idx--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }
        return ans;
}

int main(){
    string str1 ="abac";
    string str2 = "cab";
    int x = str1.size();
    int y = str2.size();
    cout<<fbu(str1,str2,x,y);
}