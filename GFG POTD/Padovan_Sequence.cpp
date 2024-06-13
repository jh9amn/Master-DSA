//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        int p0 = 1, p1 = 1, p2 = 1;
        int p3 = 0;
        for(int i=3; i<=n; i++){
            p3 = (p1 + p0)%1000000007;
            p0 = p1;
            p1 = p2;
            p2 = p3;
        }
        if(n == 0 || n == 1 || n == 2) return 1;
        return p3;
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends