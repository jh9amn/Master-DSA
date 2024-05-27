//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int n, int i, vector<int> &a, int lastTake, vector<vector<int>> &dp){
        if(i == n) return 0;
        
        // if(dp[i][lastTake] != -1) return dp[i][lastTake];
        
        int take = 0 , notTake = 0;
        
        if(abs(a[i] - lastTake) == 1 or lastTake == -1){
            take =  1 + solve(n, i+1, a, a[i], dp);
        }
        notTake = solve(n, i+1, a, lastTake, dp);
        
        return max(take, notTake);
    }
  
    int longestSubseq(int n, vector<int> &a) {
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(n, 0, a, -1, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends