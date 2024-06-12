//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        int count = 0;
        for(int i=4; i<=n; i++){
            int j = i;
            while(j){
                if(j%10 == 4) {     //  rem == 4 then count++ and leave remaining 4 digit in that num
                    count++;
                    break;
                }
                
                j /= 10;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends