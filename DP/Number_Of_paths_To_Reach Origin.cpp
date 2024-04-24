//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    // It has repetiting subproblem 2 2 -> 1, 2 or 2, 1 -> 1, 1 or 1, 1
    int mod = 1e9+7;
    int solve(int x, int y, vector<vector<int>> &dp){
        if(x == 0 || y == 0) return 1;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        return dp[x][y] = (solve(x-1, y, dp)% mod + solve(x, y-1, dp)%mod ) % mod;
    }
    
    int ways(int x, int y)
    {
        vector<vector<int>> dp(x+1,vector<int> (y+1,-1));
        return solve(x, y, dp);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends