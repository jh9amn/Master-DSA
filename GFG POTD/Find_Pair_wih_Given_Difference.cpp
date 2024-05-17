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
    int findPair(int n, int x, vector<int> &arr) {
        
        // Method 1
        // tc - O(nlongn)
        // sort(arr.begin(), arr.end());
        // int i=0;
        // int j=1;
        
        // while(i < n and  j < n){
        //     if(arr[j] - arr [i] == x and i !=j ){
        //         return 1;
        //     }
        //     else{
        //         if(arr[j] - arr[i] < x) j++;
        //         else i++;
        //     }
        // }
        // return -1;
        
        
        
        // Method 2
        // T.c - O(n)  sc-O(n)
        set<int> st;
        for(int i=0; i<n; i++){
            // ager hai to return 1
            if(st.find(arr[i] - x) != st.end() || st.find(x + arr[i]) != st.end()){
                return 1;
            }
            else st.insert(arr[i]);
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends