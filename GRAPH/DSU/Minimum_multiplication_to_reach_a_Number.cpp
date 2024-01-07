//{ Driver Code Starts
// Initial Template for C++
// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> steps(100000,1e9);
        steps[start] = 0;
        
        queue<pair<int,int>> q;  // (step,node);
        q.push({0,start});
        
        while(!q.empty()){
            int st = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node == end) return st;
            
            for(auto x : arr){
                int newNode = (x * node) % 100000;
                if(steps[newNode] > st+1){
                    steps[newNode] = st + 1;
                    q.push({st+1,newNode});
                }
            }
        }
        if(steps[end] == 1e9) return -1;
        return steps[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends