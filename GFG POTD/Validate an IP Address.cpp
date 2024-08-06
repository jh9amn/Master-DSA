//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        int n = str.size();
        int dotCount = 0;
        vector<string> arr;
        string s = "";
        for(int i=0; i<n; i++){
            if(str[i] == '.'){
                if(i>0 && i<n-1 && str[i-1] == '.' || str[i+1] == '.') return 0;
                dotCount++;
                if(dotCount > 3) return 0;
                arr.push_back(s);
                s = "";
            }
            else s += str[i];
            
            if(i == n-1){
                arr.push_back(s);
            }
        }
        
        if(arr.size() != 4) return 0;
        
        for(int i=0; i<4; i++){
            string a = arr[i];
            int val = 0;
            if(a[0] == '0' && a.size() != 1 || a.size() > 3) return 0;
            
            int number = stoi(a);
            if(number > 255 || number < 0) return 0;
        }
        
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends