//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int n, string s){
        
        int dp[201][201][2];
        memset(dp, -1, sizeof dp);
        
        function <int (int, int , string, int)> solve = [&](int idx, int n, string s, int istrue){
            if(idx > n) return 0;
            if(idx == n ){
                if(istrue && s[idx] == 'T') return 1;
                if(!istrue &&  s[idx] == 'F') return 1;
            }
            
            // if(idx == n) {
            //     return (s[idx] == (istrue == 1 ? 'T' : 'F')) ? 1 : 0 ;
            // }
            
            if(dp[idx][n][istrue] != -1) return dp[idx][n][istrue];
            int ans = 0;
            for(int i=idx + 1; i <= n-1; i+=2){
                int LT = solve(idx, i-1, s, 1);
                int LF = solve(idx, i-1, s, 0);
                int RT = solve(i+1, n, s, 1);
                int RF = solve(i+1, n, s, 0);
                
                if(s[i] == '&') {
                    ans += (istrue == 1) ? (LT * RT) : (LF * RF + LF * RT + LT * RF);
                }
                else if(s[i] == '|'){
                    ans += (istrue == 1) ? (LF * RT + LT * RF + LT * RT ) : (LF * RF);
                }
                else {
                    ans += (istrue == 1) ? (LF * RT + LT * RF) : (LT * RT + LF * RF);
                }
            }
            return dp[idx][n][istrue] = ans % 1003;
        };
        
        return solve(0,s.size() - 1, s, 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends