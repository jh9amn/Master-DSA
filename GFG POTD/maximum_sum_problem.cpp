//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
           if( n==0) return 0;
           vector<int> maxi(n+1, 0);
           
           for(int i=1; i<=n; i++){
               maxi[i] = max(i, maxi[i/2] + maxi[i/3] + maxi[i/4]);
           }
           return maxi[n];
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends