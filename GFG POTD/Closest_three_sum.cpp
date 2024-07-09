//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int ans = 0;
        int diff = INT_MAX;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n-2;i++){
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                int sum = arr[i] + arr[j] + arr[k];
                int d = abs(target - sum);
                if(d < diff) {
                    diff = d;
                    ans = sum;
                }
                else if(d == diff) {
                    ans = max(sum, ans);
                }
                
                if(sum > target) k--;
                if(sum < target) j++;
                if(target == sum) return sum;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends