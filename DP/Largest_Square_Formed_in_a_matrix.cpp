//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  // T.C = O(n*m) S.C = O(n*m)
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int maxi = 0;
        vector<vector<int>> v(n+1, vector<int> (m+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(mat[i][j] == 1){
                    // pick prevoiuse visit and +1 
                    v[i][j] = 1 + min(v[i+1][j+1], min(v[i+1][j], v[i][j+1]));
                    maxi = max(v[i][j], maxi);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends