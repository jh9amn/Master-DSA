//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        int checker = 0; // bit vector to track characters
        string result; // string to store the result
    
        for (char ch : str) {
            int val = ch - 'a'; // position of the character in the alphabet
    
            // Check if the bit for this character is already set
            if ((checker & (1 << val)) == 0) {
                result += ch; // add the character to the result
                checker |= (1 << val); // set the bit for this character
            }
        }
    
        return result;

    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends