//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        int dp[n+1][n+1];
        memset(dp, 0, sizeof dp);
        int maxLen = 0;
        int end = -1;
        
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] and j-i  > dp[i][j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                    if(dp[i+1][j+1] > maxLen){
                        maxLen = dp[i+1][j+1];
                        end = i;
                    }
                }
            }
        }
        
        if(end == -1) return "-1";
        return s.substr(end - maxLen + 1, maxLen);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends