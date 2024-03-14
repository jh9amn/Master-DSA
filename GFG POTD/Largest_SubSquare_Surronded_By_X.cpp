//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        int vert[n][n] = {0};
        int hori[n][n] = {0};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // horizontaly prefix sum and vertically prefix sum
                vert[i][j] = (a[i][j] == 'X' ? (j == 0 ? 1 : vert[i][j-1] + 1) : 0);
                hori[j][i] = (a[j][i] == 'X' ? (j == 0 ? 1 : hori[j-1][i] + 1) : 0);
            }
        }
        
        int maxi = 0;
        // starting from last because prefix sum left to right
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int size = min(vert[i][j], hori[i][j]);
                while(size > maxi){
                    // vertical matrix me  i - size  bale row me same ele and hori me j - size bale col me same element
                    // means charo kona me same prefix sum in the both vert and hori matrix
                    if(vert[i - size + 1][j] >= size && hori[i][j - size + 1] >= size){
                        maxi = size;    // max size possible
                        break;
                    }
                    else size--;        // check for smaller size
                }
            }
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends