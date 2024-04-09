//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int solve( int i, int j, int m, int n, vector<vector<int>> &points, vector<vector<int>> &dp){
	    if(i == m-1 && j == n-1) {
	        return points[i][j] > 0 ? 1 : abs(points[i][j]) + 1;
	    }
	    
	    if(dp[i][j] != INT_MIN) return dp[i][j];
	    
	    int ans = INT_MAX;
	    
	    // Right Call
	    if(j + 1 < n){
	        int x = - points[i][j] + solve(i, j+1, m, n, points, dp);
	        ans = min(ans, x);
	    }
	    
	    // Down Call
	    if(i + 1 < m){
	        int y = - points[i][j] + solve(i+1, j, m, n, points, dp);
	        ans = min(ans, y);
	    }
	    
	    dp[i][j] = ans <= 0 ? 1 : ans;
	    return dp[i][j];
	}
	
	
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	   vector<vector<int>> dp(m, vector<int> (n,INT_MIN));
	   return solve(0 , 0 , m, n, points, dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends