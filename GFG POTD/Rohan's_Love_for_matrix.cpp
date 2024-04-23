//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        int mod = 1e9 + 7;
        int a = 1;
        int b = 1;
        int ans = 0;
        
        if(n == 1 or n == 2) return 1;
        
        for(int i=3; i<=n; i++){
            ans = (a + b) % mod;
            a = b;
            b = ans;
        }
        return ans % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends