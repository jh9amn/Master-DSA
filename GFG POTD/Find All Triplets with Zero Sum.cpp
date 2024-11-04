//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        // two pointer approach but sorting not allowed..
        // sort(arr.begin(), arr.end());
        
        // for(int i=0; i<n-2; i++){
        //     int j = i+1;
        //     int k = n-1;
            
        //     if(i > 0 and arr[i] == arr[i-1]) continue;
            
        //     while(j < k){
        //         int sum = arr[i] + arr[j] + arr[k];
                
        //         if(sum == 0){
        //             ans.push_back({i, j, k});
        //             j++;
        //             k--;
                    
        //             while (j < k && arr[j] == arr[j - 1]) j++;
        //             while (j < k && arr[k] == arr[k + 1]) k--;
        //         }
        //         else if(sum < 0) j++;
        //         else k--;
        //     }
        // }
        // return ans;
        
        
        //** Hash map to find triplets...
        // Nut the last test case is not passing..
        // for(int i=0; i<n-2; i++){
        //     unordered_map<int, int> mp;
            
        //     for(int j=i+1; j<n; j++){
        //         int target = -(arr[i] + arr[j]);
        //         if(mp.find(target) != mp.end()){
        //             int k = mp[target];
        //             ans.push_back({i,k,j});
        //         }
        //         mp[arr[j]] = j;
        //     }
        // }
        // return ans;
        
        
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(arr[i] + arr[j] + arr[k] == 0){
                        ans.push_back({i,j,k});
                    }
                }
            }
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends