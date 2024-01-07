#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

// Recursion
int f1(int n){
    if(n==0 || n==1) return n;
    return f1(n-1) + f1(n-2);
}

// top Down DP
int f2(int n){
    if(n==0 || n==1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f2(n-1) + f2(n-2);
}

// Bottom Up Dp
int f3(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
         dp[i] = dp[i-1] + dp[i-2]; 
    }
    return dp[n];
}

// normal fibo approach
int f4(int n){
    int a = 0, b = 1;
    int c;
    for(int i=2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<f4(n)<<"\n";
    return 0;
}