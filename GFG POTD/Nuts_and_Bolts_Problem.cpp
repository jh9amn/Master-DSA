//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution { 
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        string temp = "!#$%&*?@^";
        
        set<char> st;
        for(int i=0; i<n; i++){
            st.insert(nuts[i]);
        }
        
        int k = 0;
        for(int i=0; i<9; i++){
            if(st.count(temp[i])) {
                nuts[k] = temp[i];
                bolts[k] = temp[i];
                k++;
            }
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends