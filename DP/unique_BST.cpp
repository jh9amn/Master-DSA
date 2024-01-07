#include<bits/stdc++.h>
using namespace std;
    int dp[20];
    // int f(int n){
    //     if(n == 0) return 1;
    //     if(n == 1) return 1;
    //     if(n == 2) return 2;
    //     if(n == 3) return 5;
    //     if(dp[n] != -1) return dp[n];
    //     int sum = 0;
    //     for(int k=1; k<=n; k++) {
    //         sum += f(k-1) * f(n-k);
    //     }
    //     return sum;
    // }

    int fbu(int n){
        memset (dp,0,sizeof dp);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4; i<=n; i++){
            for(int k=1; k<=i; k++){
                dp[i] += dp[k-1] * dp[i-k];
            }
        }
        return dp[n];
    }

    int numTrees(int n) {
        // memset(dp,-1,sizeof dp);
        // return f(n);   

        return fbu(n);
    }


int main()
{
    int n;
    cin>>n;
    cout<<fbu(n);
}
