#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
// string sdp[1005][1005];
// string s = "";

// TOP DOWN
int f(string &s1, string &s2, int i, int j){
    if(i >= s1.size() || j >= s2.size() ) return 0;
    if(s1[i] == s2[j]) return dp[i][j] = 1+f(s1,s2,i+1,j+1);
    else return dp[i][j] = max(f(s1,s2,i+1,j) , f(s1,s2,i,j+1));
}

 // BOTTOM UP
    int BUdp[1005][1005];
    int fbu(string &s1, string &s2){
        for(int i=s1.size()-1; i>=0; i--){
            for(int j=s2.size()-1; j>=0; j--){
                if(s1[i] == s2[j])  BUdp[i][j] = 1+BUdp[i+1][j+1];
                else BUdp[i][j] = max(BUdp[i+1][j], BUdp[i][j+1]);
            }
        }return BUdp[0][0];
    }

int main(){
    memset(dp,-1,sizeof dp);
    memset(BUdp,-1,sizeof BUdp);
    string s1,s2;
    cin>>s1>>s2;
    cout<<f(s1,s2,0,0);
}
