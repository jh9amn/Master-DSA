//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
  
  
    int dp[1005][1005];
    int f(string &s, string &t, int i, int j){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 1+f( s, t, i-1, j-1);
        return dp[i][j] = max(f(s,t,i-1,j) , f(s,t,i,j-1));
    }
    
     // bottom up
    int fbu(string &s, string &t, int x, int y){
        vector<vector<int>> DP(x+1,vector<int>(y+1,0));
        for(int i=0; i<=x; i++) DP[i][0] = 0;
        for(int j=0; j<=y; j++) DP[0][j] = 0;
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                if(s[i-1] == t[j-1]) DP[i][j] = 1 + DP[i-1][j-1];
                else DP[i][j] = max(DP[i-1][j] , DP[i][j-1]);
            }
        }return DP[x][y];
    }
    
    
    // LCS through bottom Up
    int solve(string s, string t, int x, int y){
        vector<vector<int>> tP(x+1, vector<int> (y+1,-1));
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                
                if( i == 0 or j == 0) tP[i][j] = 0;
                
                else if(s[i-1] == t[j-1]){
                    tP[i][j] = 1 + tP[i-1][j-1];
                }
                
                else{
                    tP[i][j] = max(tP[i][j-1] , tP[i-1][j]);
                }
            }
        }
        return tP[x][y];
    }
    
    int findMinCost(string x, string y, int costX, int costY) {
        
        int lenX = x.size();
        int lenY = y.size();
        
        int len = fbu(x, y, lenX, lenY);
        
        return costX*(lenX - len) + costY*(lenY - len);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends