//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
public:
    bool isValid(int r, int c , int n){
        if(r >= 0 && r < n && c >= 0 && c < n) return true;
        return false;
    }
    
    int dr[2] = {0 ,1};
    int dc[2] = {1, 0};
    
    ll f(int r, int c, int n, int sum, vector<vector<vector<ll>>> &dp, vector<vector<int>> &arr){
        if( r == n-1 && c == n-1) return dp[r][c][sum] = sum == arr[r][c];
        
        if(dp[r][c][sum] != -1) return dp[r][c][sum];
        
        dp[r][c][sum] = 0;
        if(arr[r][c] <= sum){
            for(int dir = 0; dir < 2; dir++){
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                
                if(isValid(nr, nc , n)){
                    dp[r][c][sum] += f(nr, nc, n, sum - arr[r][c], dp, arr);
                }
            }
        }
        return dp[r][c][sum];
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>> (n+1,vector<ll> (k+1, -1)));
        return f(0, 0 , n, k, dp, arr);
        
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends



// JAVA CODE with Memoization




// import java.io.*;
// import java.util.*;

// class GFG
// {
//     public static void main(String args[])throws IOException
//     {
        
//         BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
//         int t = Integer.parseInt(read.readLine());
//         while(t-- > 0)
//         {
            
//             int  k = Integer.parseInt(read.readLine());
//             int  n = Integer.parseInt(read.readLine());
//             int arr[][] = new int[n][n];
//             String input_line1[] = read.readLine().trim().split("\\s+");
//             int c = 0;
//             for(int i=0;i<n;i++){
//                 for(int j = 0;j<n;j++){
//                     arr[i][j] = Integer.parseInt(input_line1[c]);
//                     c++;
//                 }
//             }
//             Solution obj = new Solution();
//             System.out.println(obj.numberOfPath(n, k, arr));
//         }
//     }
// }



//User function Template for Java

// class Solution {
//     int ans;
//     long numberOfPath(int n, int k, int [][]arr) {
//        ans = 0; 
//        dfs(0,0,n,k,arr);
//        return ans;
//     }
    
//     void dfs(int r, int c, int n, int k, int [][]arr){
//         if( k < 0) return;
//         if( r < n && c < n && r >= 0 && c >= 0) {
//             if(r == n-1 &&  c == n-1) {
//                 if (k == arr[r][c])
//                     ans++;
//             }
//             dfs(r+1, c, n , k - arr[r][c], arr);
//             dfs(r, c+1, n, k - arr[r][c], arr);
//         }
//     }
// }