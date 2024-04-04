//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        long long ans = 0, previous = 0, mod = 1e9 + 7;
        for(long long i = 0; i< s.size(); i++){
            // formula = previous + (s[i] * i + 1) where i = index + 1
            long long curr = (previous * 10)%mod + (s[i] - '0') * (i + 1);
            previous = curr;
            ans += curr;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends