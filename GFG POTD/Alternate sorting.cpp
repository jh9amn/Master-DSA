//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        vector<int> a = arr;
        sort(a.begin(), a.end());
        vector<int> b = arr;
        sort(b.begin(), b.end(), greater<int>());
        
        int sizee = arr.size();
        int m = 0;
        int n = 0;
        
        for(int i=0; i<sizee; i++){
            if(i % 2 == 0){ 
                arr[i] = b[m++];
            }
            else if(i % 2 != 0){ 
                arr[i] = a[n++];
            }
        }
        return arr;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends