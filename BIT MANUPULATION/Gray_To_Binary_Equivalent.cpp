//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // T.C = O(m) == no of time to convert into bit
    // S.C - O(m) == to Storing all the Bit
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        vector<int> ans;
        // converting in Binary
        while(n){
            if(n & 1 == 1) ans.push_back(1);
            else ans.push_back(0);
            n>>=1;
        }
        
        // reverse it to get the proper order 
        reverse(ans.begin(), ans.end());
        
        
        // converting the Binary Into The Gray Code
        for(int i=1; i<ans.size(); i++){
            ans[i] = ans[i-1] ^ ans[i];
        }
        
        // decimal representation of this Gray code
        int res = 0; int j = 0;
        for(int i = ans.size()-1; i>=0; i--){
            if(ans[i] == 1) res += pow(2,j);
            j++;
        }
        return res;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends