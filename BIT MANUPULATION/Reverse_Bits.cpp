//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    T.C - O(1) S.X=C - O(1)
    long long reversedBits(long long x) {
        
        // filling the bits...
        vector<int> bit;
        int i = 0;
        while(x || i != 32){
            if(x & 1 == 1) bit.push_back(1);
            else bit.push_back(0);
            x >>= 1;
            i++;
        }
        
        int j = 0;
        long long ans = 0;
        
        // calculating the bits values..
        for(int i=32-1; i>=0; i--){
            if(bit[i] == 1) {
                ans += pow(2,j);
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends