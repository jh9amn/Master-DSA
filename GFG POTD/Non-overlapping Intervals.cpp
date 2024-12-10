//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        
        // sort according the endtime..
        sort(begin(intervals), end(intervals), [] (vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        
        int n = intervals.size();
        int count = 0;
        
        int LastIntervalEndtime = intervals[0][1];
        
        for(int i=1; i<n; i++){
            if(intervals[i][0] < LastIntervalEndtime) count++;
            else LastIntervalEndtime = intervals[i][1];
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends