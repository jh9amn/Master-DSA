#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1
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
    
    
    // Approach 2       T.C = O(n^2)     S.C = O(n^2)
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
    
    
    // Approach 3 using Stack    T.C = O(n)   S.C = O(n)
    bool solve2(string &s){
        // here store the index to compare that the symbol ocmes first or * comes first to remove that symbol
        stack<int> st;
        stack<int> star;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == '(') st.push(i);
            
            else if(s[i] == ')') {
                if(st.size() > 0) st.pop();     // if ( is available
                else if(star.size() > 0) star.pop();       // if (  is not available but * is available
                else return false;        // return false
            }
            
            else if(s[i] == '*') {
                star.push(i);
            }
        }
        
        while(!st.empty() and star.size() > 0){
            if(st.top() < star.top()) {
                st.pop();
                star.pop();
            }
            else return false;
        }
        return st.size() == 0 ? true : false;
    }
    
    
    // Approach 4 leftCount and rightCount Approach
    // T.C = O(n)   S.C = O(1)
    bool solve3(string s, int n){
        int openBrackets = 0, closeBrackets = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(' or s[i] == '*')  openBrackets++;
            else openBrackets--;
            if(openBrackets < 0) return false;
        }
        
        for(int i=n-1; i>=0; i--){
            if(s[i] == ')' or s[i] == '*') {
                closeBrackets++;
            }
            else closeBrackets--;
            if(closeBrackets < 0) return false;
        }
        return true;
    }
    
    bool checkValidString(string s) {
        int dp[101][101];
        memset(dp, -1, sizeof dp);
        int n = s.size();
        // return solve(0, 0, s, n, dp);
        
        // return solve_Tabulation(n, s);
        
        // Using Stack
        // return solve2(s);
        
        return solve3(s,n);
    }
};



int main(){



}