#include<bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2){
    
    int n1 = str1.size();
    int n2 = str2.size();

    int dp[n1+1][n2+1] = {0};
    memset(dp,0, sizeof(dp));

    int res = 0;
    // for(int i=0; i<=n1; i++) dp[i][0] = 0;
    // for(int j=0; j<=n2; j++) dp[0][j] = 0;

    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            // because str has max index size - 1
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                res = max(res, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return res;
}


int main(){

}