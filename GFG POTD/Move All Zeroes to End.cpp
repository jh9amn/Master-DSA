//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int countZero = 0;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0) countZero++;
        }
        
        int i = 0;
        int n = arr.size();
        int idx = 0;
        while(i != n){
            if(arr[i] != 0){
                arr[idx] = arr[i];
                idx++;
            }
            i++;
        }
        while(countZero--){
            arr[idx] = 0;
            idx++;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends