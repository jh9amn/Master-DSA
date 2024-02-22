//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int size_S = s.size();
        int size_T= t.size(); 
        int mod = 1e9 + 7;
        // int dp[size_S][size_T];
        // memset(dp, -1, sizeof dp);
        vector<vector<int>> dp(size_S, vector<int> (size_T,-1));
        
        function<int(string, string, int, int)> solve = [&](string s, string t, int i, int j){
           if(j == t.size()) return 1;
           if(i == s.size()) return 0;
           
           if(dp[i][j] != -1) return dp[i][j];
           
           if(s[i] == t[j]){
              return dp[i][j] =  solve(s, t, i + 1, j + 1) % mod + solve(s, t, i + 1, j) % mod; // take or not take
           }
           return dp[i][j] =  solve(s, t, i + 1, j) % mod;
           
        };
        
        return solve(s, t, 0, 0) % mod;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends