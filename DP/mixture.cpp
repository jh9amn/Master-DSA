#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int sum(vector<int> &v,int i,int j){
    int sum = 0;
    for(int m=i; m<=j; m++){
        sum += v[m];
        sum %= 100;
    }
    return sum;
}

int f(vector<int> &v,int i, int j){
    // memset(dp,-1,sizeof dp);
    if(i == j) dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    int res = INT_MAX;
    for(int k=i; k<j; k++){
        res = min(res,f(v,i,k) + f(v,k+1,j) + sum(v,i,k) * sum (v,k+1,j));
    }
    return dp[i][j] = res;
}


int fbu(vector<int> &v){
    int n = v.size();
    memset(dp,0,sizeof dp);
    for(int i=0; i<n; i++){
        dp[i][i] = 0;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            int res = INT_MAX;
            for(int k=i; k<j; k++){
                res = min(res,dp[i][k] + dp[k+1][j] + sum(v,i,k) * sum (v,k+1,j));
            }
            dp[i][j] = res;
        }
    } return dp[0][n-1];
}



int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
    // top down
    cout<<f(arr,0,n-1)<<"\n";

    // bottom up
    cout<<fbu(arr);
}

// for spoj
// int main(){
//     int n;
//     while(cin>>n)   {
//         vector<int> arr(n);
//         for(int i=0; i<n; i++){
//             cin>>arr[i];
//         }
//         memset(dp,-1, sizeof dp);
//         cout<<f(arr,0,n-1)<<"\n";
//     }   
// }

/*
 Input:
2
18 19
3
40 60 20

Output:
342
2400*/