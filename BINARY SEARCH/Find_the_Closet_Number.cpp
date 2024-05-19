//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int l = 0;
        int h = n-1;
        
        int ans = arr[0];
        while(l <= h){
            int m = l + (h-l)/2;
            
            if(abs(k - arr[m]) == abs(k - ans)) ans = max(arr[m], ans);
            else if(abs(k - arr[m]) < abs(k - ans)) ans = arr[m];
            
            if(arr[m] == k) return arr[m];
            else if(arr[m] > k) h = m - 1;
            else l = m + 1;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends