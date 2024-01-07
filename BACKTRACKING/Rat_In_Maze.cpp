//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isValid(int i, int j, int n){
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    
    void find(int i, int j, vector<vector<int>> &maze, int n, string s, vector<string> &ans){
        
        if( i == n-1 && j == n-1) {
            ans.push_back(s);
            return;
        }
        // Lexographically Order Route
        string route = "DLRU";
        int dr[4] = {1, 0, 0, -1 };
        int dc[4] = {0, -1, 1 , 0};
        
        for(int idx=0; idx<4; idx++){
            int nr = dr[idx] + i;
            int nc = dc[idx] + j;
            if(isValid(nr, nc, n) && maze[nr][nc] == 1){
                maze[i][j] = 2;         // marked visited means don't go back
                find(nr, nc, maze, n, s + route[idx], ans);
                maze[i][j] = 1;     // after coming from the route mark its actual value
            }
        }
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
         if(m[0][0] == 1){
            find(0,0,m,n,"",ans);
        }
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends