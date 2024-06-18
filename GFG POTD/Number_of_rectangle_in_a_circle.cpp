//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int count = 0;
        
        // x^2 + y^2 = h^2 = (r * r)^2
        for(int x = 1; x <= 2*r; x++){
            for(int y = 1; y <= 2*r; y++){
                if(x*x + y*y <= 4 * r* r) count++;      // pythagorous Theorem
            }
        }
        return count;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends