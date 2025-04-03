//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n,m;
    bool isValid(int i, int j) {
        return i >=0 && i < n && j >= 0 && j < m;
    }
    void solve(queue<pair<int, int>> &q, vector<vector<int>> &mat, int &ans, int &fresh) {
        int dir[][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        
        while(!q.empty()) {
            int rottHappen = false;
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                auto it = q.front();
                int curri = it.first;
                int currj = it.second;
                q.pop();
                
                for(auto d : dir) {
                    int newi = d[0] + curri;
                    int newj = d[1] + currj;
                    
                    if(isValid(newi, newj) && mat[newi][newj] == 1) {
                        mat[newi][newj] = 2;
                        q.push({newi, newj});
                        fresh--;
                        rottHappen = true;
                    }
                }
            }
            if(rottHappen) ans++;
        }
    }
    
    int orangesRotting(vector<vector<int>>& mat) {
        int ans = 0;
        n = mat.size();
        m = mat[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 2) q.push({i,j});
                else if(mat[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        solve(q, mat, ans, fresh);
        return fresh > 0 ? -1 : ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends