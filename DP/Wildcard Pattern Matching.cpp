//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[200][200];
    int solve(string pattern, string str, int i, int j){
        if(i == pattern.size() and j == str.size()) return 1;
        if(i == pattern.size()) return 0;
        if(j == str.size() and pattern[i] == '*') return solve(pattern, str, i+1, j);
        if(j == str.size()) return 0;
        if(pattern[i] != '*' and pattern[i] != '?' and pattern[i] != str[j]) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int x = 0, y = 0, z = 0;
        if(pattern[i] == '*'){
            x = solve(pattern, str, i + 1, j);
            y = solve(pattern, str, i, j + 1);
        }
        
        z = solve(pattern, str, i + 1, j + 1);
        
        return dp[i][j] = x || y || z;
    }
    int wildCard(string pattern, string str) {
        memset(dp, -1, sizeof dp);
        return solve(pattern, str, 0, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends