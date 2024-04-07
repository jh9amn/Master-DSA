//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int solve(int i, int j, int n, int m, int a[], int b[], vector<vector<int>> &dp, int diff){
	    if(i == n || j == m) return 0;
	    int sum1 = 0, sum2 = 0;
	    
	    if(dp[i][j] != -1) return dp[i][j];
	    
	    if(diff > 0){
	        // leave
	        sum1 = solve(i+1, j, n, m, a, b, dp, diff - 1);
	        // take
	        sum2 = a[i] * b[j] + solve(i+1, j+1, n, m, a, b, dp, diff);

	    }
	    // difference over then multiply all
	    sum2 = a[i] * b[j] + solve(i+1, j+1, n, m, a, b, dp, diff);
	    
	    return dp[i][j] =  max(sum1, sum2);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		int diff = n - m;
		vector<vector<int>> dp(n, vector<int> (m,-1));
		return solve(0,0,n,m,a,b,dp,diff);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends