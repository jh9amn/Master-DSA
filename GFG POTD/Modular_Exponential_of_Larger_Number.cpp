//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	// (a*b) % m = ((a%m) * (b%m)) % m
	
	    long long int solve(long long int x, long long int n,long long int M){
	        if(n == 0) return 1;
	        if(n == 1) return x;
	        
	        long long int temp = solve(x, n/2, M);
	        
	        temp = (temp * temp)%M;
	        
	        // odd to return this
	        if( n%2== 1) return (temp *  x)%M;
	        
	        return temp;
	    }
	    
	    
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int ans = solve(x, n, M) ;
		    return ans % M;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends