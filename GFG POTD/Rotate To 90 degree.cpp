//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
 
 /**
 Original Matrix:

[1 2 3
 4 5 6
 7 8 9
]

After Transposing:

[ 1 4 7
  2 5 8
  3 6 9
]
 
After Reversing Each Row:

[ 7 4 1 
  8 5 2 
  9 6 3 
]
*/
 
void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    // perform transpose
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // perform reverse by rows direction
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
}


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends