//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        string ans = "";
        int n = arr.size(); 
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=0; j<n; j++){
                temp += to_string(arr[i][j]);
            }
            string s = temp;
            reverse(temp.begin(), temp.end());
            if(s == temp){ 
                ans += to_string(i);
                ans += " R";
                return ans;
            }
            
        }
        
        if(ans.size() == 0) {
            for(int j=0; j<n; j++){
                string temp = "";
                int i=0;
                for(i; i<n; i++){
                    temp += to_string(arr[i][j]);
                }
                string s = temp;
                reverse(temp.begin(), temp.end());
                if(s == temp){ 
                    ans += to_string(j);
                    ans += " C";
                    return ans;
                } 
            }
        }
        
        
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends