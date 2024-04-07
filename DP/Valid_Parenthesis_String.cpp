#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // without memeization worst time complexity is O(3^n)
    // T.C =  O(n^2)      S.C = O(n^2)
    bool solve(int i, int open, string &s, int n, int dp[][101]){
        if(i == n){
            return open == 0 ? true : false;
        }
        // lets thing that not possible
        bool isValid = false;
        
        if(dp[i][open] != -1) return dp[i][open];
        
        // ifs[i] == (
        if(s[i] == '('){
            isValid |= solve(i+1, open + 1, s, n, dp);
        }
        
        else if(s[i] == '*'){
            // if we choose * == (
            isValid |= solve(i+1, open + 1, s, n, dp);
            // if we choose * == ""
            isValid |= solve(i+1, open, s, n, dp);
            // if we choose * == )
            if(open > 0) isValid |= solve(i+1, open - 1, s, n, dp);
        }
        // if s[i] == )
        else if(open > 0){
            isValid |= solve(i+1, open - 1, s, n, dp);
        }
        
        return dp[i][open] = isValid;
    }
    
    
    // Approach 2
    bool solve_Tabulation(int n, string &s){
        vector<vector<bool>> dp(n+1,vector<bool> (n+1, false));
        
        // starting open breackets == 0 or empty string 
        dp[n][0] = true;
        
        for(int i=n-1; i>=0; i--){
            for(int open = 0; open <= n; open++){
                bool isValid = false;
                if(s[i] == '('){
                    isValid |= dp[i+1][open+1];
                }
                else if(s[i] == '*'){
                    isValid |= dp[i+1][open+1];
                    isValid |= dp[i+1][open];
                    if(open > 0) isValid |= dp[i+1][open-1];
                }
                else if(open > 0){
                    isValid |= dp[i+1][open-1];
                }
                dp[i][open] = isValid;
            }
        }
        // at last of i return open ka 0th idx value
        return dp[0][0];
    }
    
    
    bool checkValidString(string s) {
        int dp[101][101];
        memset(dp, -1, sizeof dp);
        int n = s.size();
        // return solve(0, 0, s, n, dp);
        
        return solve_Tabulation(n, s);
    }
};



int main(){



}