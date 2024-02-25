//{ Driver Code Starts
// Driver Code

// https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	vector<long long int> v(n+1,0);
    	v[0] = 1;
    	
    	for(long long int i=3; i<=n; i++){
    	   v[i] += v[i-3];
    	   
    	}
    	for(long long int i=5; i<=n; i++){
    	   v[i] += v[i-5];
    	}
    	for(long long int i=10; i<=n; i++){
    	   v[i] += v[i-10];
    	}
    	
    	return v[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends