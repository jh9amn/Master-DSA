//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        bool flag1 = true;
        bool flag2 = false;
        // min length should atleast 1 beacuse (arr.minSize = 1)
        int temp1 = 1;
        int temp2 = 1;
        
        for(int i=0; i<arr.size()-1; i++){
            if(flag1 and arr[i] < arr[i+1]) {
                temp1++;
                flag1 = false;
            }
            else if(!flag1 and arr[i] > arr[i+1]){
                temp1++;
                flag1 = true;
            }
            
            
            if(!flag2  and arr[i] > arr[i+1]){
                temp2++;
                flag2 = true;
            }
            else if(flag2  and arr[i] < arr[i+1]){
                temp2++;
                flag2 = false;
            }
        }
        
        return max(temp1, temp2);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends