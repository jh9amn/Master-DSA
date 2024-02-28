//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.size();
        int a = 1;
        int number = 0;
        for(int i=n-1; i>=n-4; i--){
            int temp = s[i] - '0';
            number += temp * a;
            a =  a * 10;
        }
        
        if( number == 0) return 1;
        if(number % 8 == 0) return 1;
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends