#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Memoization
    int f(string word1, string word2, int i, int j, vector<vector<int>> &dp ){
        if( i < 0) return j + 1;
        if( j < 0) return i + 1;
        
        
        if(dp[i][j] != -1) return dp[i][j];
        // if ( ith idx and jth idx match)
        if(word1[i] == word2[j])  return dp[i][j] =  0 + f(word1, word2, i-1, j-1, dp);
        
                                    // remove
        return dp[i][j] =  1 +  min(f(word1, word2, i-1, j, dp),
                            // insert                       // replace
                        min(f(word1, word2, i, j-1, dp) , f(word1, word2, i-1, j-1, dp)));
        
    }
    
    // Tabulation
    int f2 (string s1, string s2, int n, int m){
        // 1 base indexing
        // if(n == 0) return m;
        // if(m == 0) return n;
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // shifting all index to +1
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] =  0 + dp[i-1][j-1];
        
                                      // remove
                else dp[i][j] =  1 +  min(dp[i-1][j],
                            // insert     // replace                  
                        min(dp[i][j-1] , dp[i-1][j-1]));
            }
        }
        
        return dp[n][m];
        
        
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp (n,vector<int> (m,-1));
    //  memoization
    //  return f(word1, word2, n-1, m-1 ,dp);
        
        // Tabulation on 1 base Indexing
        return f2(word1, word2,n,m);
    }
};


int main(){

}