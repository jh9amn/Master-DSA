/* https://www.spoj.com/problems/UPDATEIT/ */

#include<bits/stdc++.h>
using namespace std;

// Function to get prefix sum till index idx
int query(int idx, int bit[]){

    int ans = 0;

    // Traverse BIT towards parent nodes
    while(idx > 0){

        ans += bit[idx];

        // Move to parent
        idx -= idx & (-idx);
    }

    return ans;
}

// Function to update BIT
// Adds val at index idx
void update(int idx, int val, int bit[], int n){

    // Update all responsible nodes
    while(idx <= n){

        bit[idx] += val;

        // Move to next responsible node
        idx += idx & (-idx);
    }
}

int main(){

    // Number of test cases
    int t;
    cin >> t;

    while(t--){

        // Size of array
        int n;
        cin >> n;

        // BIT array initialized with 0
        int bit[n + 10] = {0};

        // Number of update operations
        int u;
        cin >> u;

        while(u--){

            int l, r, inc;
            cin >> l >> r >> inc;

            // Convert 0-based indexing to 1-based indexing
            l++;
            r++;

            // Difference Array Concept using BIT

            // Add inc from index l onwards
            update(l, inc, bit, n);

            // Subtract inc after r
            update(r + 1, -inc, bit, n);

            // Effectively:
            // A[l...r] += inc
        }

        // Number of queries
        int q;
        cin >> q;

        while(q--){

            int w;
            cin >> w;

            // Convert to 1-based indexing
            w++;

            // Query gives actual value at index w
            cout << query(w, bit) << endl;
        }
    }
}