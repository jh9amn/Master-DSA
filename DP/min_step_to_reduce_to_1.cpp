// minimum step to reduce the digit to 1....

#include<iostream>
#include<bits/stdc++.h>
#define IMAX INT_MAX
using namespace std;

// recursive solution
int f(int n){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    return 1 + min({f(n-1) ,(n%2 == 0) ? f(n/2) : INT_MAX ,(n%3 == 0) ? f(n/3) : INT_MAX});
}

//Dp Top Down
vector<int> dp;
int ftd(int n){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = 1 + min({f(n-1), (n%2 == 0) ? f(n/2): IMAX, (n%3 == 0) ? f(n/3) : IMAX});
}
int main(){
    dp.clear();
    dp.resize(105,-1);
    cout<<ftd(10)<<"\n";
}