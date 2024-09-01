//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size()-1;
        int m = arr2.size()-1;
        
        int sum1 = 0; int sum2 = 0;
        
        while(n >= 0 and  m >= 0){
            
            if(arr1[n] < arr2[m]){
                sum2 += arr2[m];
                m--;
            }
            else if(arr1[n] > arr2[m]){
                sum1 += arr1[n];
                n--;
            }
            else {
                if(sum1 > sum2){
                    sum1 += arr1[n];
                    sum2 = sum1;
                }
                else{
                    sum2 += arr2[m];
                    sum1 = sum2;
                }
                n--;
                m--;
            }
        }
        

        while(n >= 0){
            sum1 += arr1[n];
            n--;
        }
        while(m >= 0){
            sum2 += arr2[m];
            m--;
        }
        return max(sum1, sum2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends