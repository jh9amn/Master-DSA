//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        int i=0;
        int j=0;
        int n = a.size();
        int m = b.size();
        
        vector<int> ans;
        
        while(i < n and j < m){
            if(ans.size() > 0 and (ans.back() == a[i] || ans.back() == b[j])) continue;
            if(a[i] < b[j] ) {
                ans.push_back(a[i]);
                i++;
            }
            else if(a[i] > b[j] ){
                ans.push_back(b[j]);
                j++;
            }
            else {
                ans.push_back(a[i]);
                i++; 
                j++;
            }
        }
        
        while(i != n) {
            if(ans.size() > 0 and ans.back() == a[i]) continue;
            ans.push_back(a[i]);
            i++;
        }
        
        while(j != m){
            if(ans.size() > 0 and ans.back() == b[j]) continue;
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends