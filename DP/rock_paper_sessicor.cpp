// D. Bad Luck Island
//https://codeforces.com/problemset/problem/540/D

#include<vector>
#include<iostream>
#include<cstring>
#include<iomanip>
#define ld long double 
using namespace std;
ld dp[105][105][105];
ld f_rock(int r, int s, int p){
    if(r == 0) return 0.0;
    if(s == 0) return 0.0;
    if(p == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    ld total = r*p + s*p + s*r;
    ld ans = 0.0;
    ans += f_rock(r-1,s,p) * ((r*p)/total);
    ans += f_rock(r,s-1,p) * ((r*s)/total);
    ans += f_rock(r,s,p-1) * ((s*p)/total);
    return dp[r][s][p] = ans;
}

ld f_scissor(int r, int s, int p){
    if(p == 0) return 0.0;
    if(s == 0) return 0.0;
    if(r == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    ld total = r*p + s*p + s*r;
    ld ans = 0.0;
    ans += f_scissor(r-1,s,p) * ((r*p)/total);
    ans += f_scissor(r,s-1,p) * ((r*s)/total);
    ans += f_scissor(r,s,p-1) * ((s*p)/total);
    return dp[r][s][p] = ans;
}

ld f_paper(int r, int s, int p){
    if(p == 0) return 0.0;
    if(r == 0) return 0.0;
    if(s == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    ld total = r*p + s*p + s*r;
    ld ans = 0.0;
    ans += f_paper(r-1,s,p) * ((r*p)/total);
    ans += f_paper(r,s-1,p) * ((r*s)/total);
    ans += f_paper(r,s,p-1) * ((s*p)/total);
    return dp[r][s][p] = ans;
}

int main(){
   ld rock,paper,scissor;
   cin>>rock>>scissor>>paper;
   memset(dp,-1, sizeof dp);
   ld ans_rock = f_rock(rock,scissor,paper);
   memset(dp,-1,sizeof dp);
   ld ans_scissor = f_scissor(rock,scissor,paper);
   memset(dp,-1,sizeof dp);
   ld ans_paper = f_paper(rock,scissor,paper);
   cout<<fixed<<setprecision(12)<<ans_rock<<" "<<fixed<<setprecision(12)<<ans_scissor<<" "<<fixed<<setprecision(12)<<ans_paper;
}

/*
3 1 1
0.285714285714 0.057142857143 0.657142857143
*/