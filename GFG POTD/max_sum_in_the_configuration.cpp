//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Approach 1st (TLE)
        
        // long long maxi = 0;
        // for(int i=0; i<n; i++){
        //     long long sum = 0;
            
        //     // (0+0)%3 = 0  (0+1)%3 = 1     (0+2) %3 = 2
        //     // (1+0)%3 = 1  (1+1)%3 = 2     (1+2)%3=0
        //     // (2+0)%3 = 2  (2+1)%3 = 0     (2+2)%3=1
            
        //     for(int j=0; j<n; j++){
        //         sum += j * a[(i + j) % n];      // accessing the value by changing the index in the range of n
        //     }
        //     maxi = max(sum, maxi);
        // }
        // return  maxi;
        
        
        
        
        // Approach 2
        long long sum = 0;
        long long prev_sum = 0;
        
        for(int i=0; i<n; i++){
            prev_sum += (long long)i*a[i];
            sum += a[i];
        }
        
        long long ans = prev_sum;
        
        
        for(int i=1; i<n; i++){
            long long curr_sum = prev_sum - (sum - a[i-1]) + (long long)a[i-1]*(n-1);
            
            prev_sum = curr_sum;
            
            ans = max(ans, curr_sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends