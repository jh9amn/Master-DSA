//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int bs (vector<int> a, int target){
        int s = 0;
        int l = a.size()-1;
        
        int ans = 0;
        
        while(s <= l){
            int mid = s + (l - s)/2;
            
            if(a[mid] == target){
                ans = mid;
                l = mid - 1;
            }
            else if(a[mid] > target){
                l = mid - 1;
            }
            else {
                 s = mid + 1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        int targetIdx = bs(arr, target);
        
        int count = 0;
        for(int i = targetIdx; i<arr.size(); i++){
            if(arr[i] == target) count++;
            else break;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends