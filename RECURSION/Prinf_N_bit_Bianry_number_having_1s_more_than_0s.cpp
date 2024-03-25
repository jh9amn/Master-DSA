//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(string s, int ones, int zeros, int n, vector<string> &ans){
        if(ones < zeros) return;
        
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        
        // One time add 1
        solve(s + '1', ones + 1, zeros, n, ans);
        // One time add 0
        solve(s + '0', ones, zeros + 1, n, ans);
    }
    
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    solve("", 0, 0, n, ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends