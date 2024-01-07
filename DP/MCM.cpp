// matrix chain multiplication

#include<bits/stdc++.h>
using namespace std;
int dp[50][50];
int f(vector<int> &v, int i, int j){
    // there is only one matrix
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    // different partition
    for(int k=i; k<j; k++){
        int res = v[i-1] * v[k] * v[j] + f(v,i,k) + f(v,k+1,j); 
        if(res < mini) mini = res;
    }
    return dp[i][j] = mini;
}

int fbu(vector<int> &v, int n){
    int dp[n][n];
    // base case (i==j) return 0 bala
    for(int i=1; i<n; i++){
        dp[i][i] = 0;
    }
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){
            int mini = 1e9;
            for(int k=i; k<j; k++){
                int res = v[i-1] * v[k] * v[j] + dp[i][k] + dp[k+1][j];
                if(res < mini) mini = res;
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}


int main(){
    vector<int> v = {10,20,30,40,50 };
    int n = v.size();
    memset(dp,-1,sizeof dp);
    cout<<f(v,1,n-1) <<"\n";

    // tabulation 
    cout<<fbu(v,n)<<"\n";



/*
index 0->1 1st matrix
index 1->2 2nd matrix
index 2->5 3rd matrix
and son
*/
}