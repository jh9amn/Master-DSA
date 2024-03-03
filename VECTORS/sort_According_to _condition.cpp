//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &a) {
	    sort(a.begin(), a.end(), [](string &e1, string &e2){ 
	        string ab = e1 + e2;
	        string ba = e2 + e1;
	        return ab > ba;
            // if( ab > ba then the is already produce the large Number, return true and do not change in the order)
            // else swap the order
	    } );
	    
	    string res = "";
	    
	    for(int i=0; i<n; i++){
	        res += a[i];
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends