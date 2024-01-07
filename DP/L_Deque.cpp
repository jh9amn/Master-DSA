// https://atcoder.jp/contests/dp/tasks/dp_l
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[3005];
ll dp[3005][3005];
ll f(int i, int j){
    if(i==j) return arr[i];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] =  max(arr[i] - f(i+1,j), arr[j] - f(i,j-1));
}

// baki hai likhna
ll fbu(int n){
    for(int i=0; i<n; i++){
        dp[i][i] = arr[i];
    }

}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // top down
    // memset(dp,-1,sizeof dp);
    // cout<<f(0,n-1);
}