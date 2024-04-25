//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        int maxi = INT_MIN;
        if(n <= 2 and m <= 2) return -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i + 2 < n and j + 2 < m){
                    int ans = mat[i][j] + mat[i][j+1] + mat[i][j+2] + mat[i+1][j+1]+ mat[i+2][j] + mat[i+2][j+1] +mat[i+2][j+2];
                    maxi = max(ans,maxi);
                }
            }
        }
        return maxi != INT_MIN ? maxi : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends