//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSingle(int n, int arr[]){
        // Number frequency is two time or one time then this process is applicable..
        // int num = n /2 + 1;
        // int numSum = num * (num + 1)/2;
        // numSum *= 2;
        
        int XOR = 0;
        for(int i=0; i<n; i++){
            XOR ^= arr[i];
        }
        return XOR;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends