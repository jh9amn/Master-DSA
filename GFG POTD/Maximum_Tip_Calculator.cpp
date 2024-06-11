//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  #define ll long long
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
    
        // int temp[n][3];
        vector<vector<int>> temp(n, vector<int> (3,0));
        
        for(int i=0; i<n; i++){
            temp[i][0] = abs(arr[i] - brr[i]);
            temp[i][1] = arr[i];
            temp[i][2] = brr[i];
        }
        
        // sort(temp.begin(), temp.end(), [&temp] (int p[], int q[]) -> p[0] - q[0];);

        // sort in the basis of arr[0][i] in decencing order 
        sort(temp.rbegin(), temp.rend());

        
        // for(auto it : temp){
        //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
        // }
        
        ll ans = 0;
        for(int i=0; i<n; i++){
            if(x == 0){
                ans += temp[i][2];
                y--;
                
            }
            
            else if(y == 0){
                ans += temp[i][1];
                x--;
            }
            
            else {
                if(temp[i][1] >= temp[i][2]) {
                    ans += temp[i][1];
                    x--;
                }
                if(temp[i][1] < temp[i][2]){
                    ans += temp[i][2];
                    y--;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends