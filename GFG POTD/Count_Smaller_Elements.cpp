//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    int bs( vector<int> temp, int val){
        int index = -1;
        
        int i = 0; 
        int j = temp.size()-1;
        
        while(i<=j){
            int mid = (i+j)/2;
            
            if(temp[mid] == val) {
                index = mid;
                j = mid - 1;
            }
            
            else if(temp[mid] > val){
                j = mid - 1;
            }
            else i = mid + 1;
        }
        return index;
    }
    
    vector<int> constructLowerArray(vector<int> &arr) {
        
        vector<int> temp = arr;
        
        sort(temp.begin(), temp.end());
        
        vector<int> ans;
        
        // sort karke compare kiya ki arr[i] = temp ke kon se index par hai
        // usse badd arr[i] ko temp se hta diya
        
        for(int i=0; i<arr.size(); i++){
            int index = bs(temp, arr[i]);
            ans.push_back(index);
            temp.erase(temp.begin() + index);
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends