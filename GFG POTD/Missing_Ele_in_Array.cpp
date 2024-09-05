//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
    
        // Method 1:
        // int xorFull = 0;    // XOR of all numbers from 1 to n
        // int xorArr = 0;     // XOR of all elements in the array
        
        // // XOR all numbers from 1 to n
        // for (int i = 1; i <= n; i++) {
        //     xorFull ^= i;
        // }
        
        // // XOR all elements in the given array
        // for (int num : arr) {
        //     xorArr ^= num;
        // }
        
        // // XOR of xorFull and xorArr will give the missing number
        // return xorFull ^ xorArr;
        
        
        
        // Method 2:
        int totalSum = n * (n+1)/2;
        int arrSum = 0;
        for(int it : arr){
            arrSum += it;
        }
        return totalSum - arrSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends