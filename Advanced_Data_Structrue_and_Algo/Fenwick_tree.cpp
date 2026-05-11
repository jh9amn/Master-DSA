#include<bits/stdc++.h>
using namespace std;

int n;

// Fenwick Tree / BIT array
vector<int> bit;

// Function to update value at index idx
// Adds 'val' to index idx
void update(int idx, int val){

    // Update all responsible nodes in BIT
    while(idx <= n) {

        bit[idx] += val;

        // Move to next responsible index
        idx += idx & (-idx);
    }
}

// Function to get prefix sum from 1 to idx
int query(int idx){

    int ans = 0;

    // Traverse parent nodes
    while(idx > 0){

        ans += bit[idx];

        // Move to parent index
        idx -= idx & (-idx);
    }

    return ans;
}

int main(){

    // Input size of array
    cin >> n;

    // Initialize BIT with size n+1
    // 1-based indexing is used
    bit = vector<int>(n + 1);

    // Original array
    vector<int> a(n + 1);

    // Input array elements
    // and build BIT
    for (int i = 1; i <= n; i++){

        cin >> a[i];

        // Add current element to BIT
        update(i, a[i]);
    }

    // Number of queries
    int q;
    cin >> q;

    // Process queries
    while(q--){

        // Query type
        int t;
        cin >> t;

        // Type 1 -> Range Sum Query
        if(t == 1){

            int l, r;
            cin >> l >> r;

            // Sum from l to r
            int ans = query(r) - query(l - 1);

            cout << ans;
        }

        // Type 2 -> Point Update
        else if(t == 2){

            int idx, val;
            cin >> idx >> val;

            // Remove old value from BIT
            update(idx, -a[idx]);

            // Update array value
            a[idx] = val;

            // Add new value to BIT
            update(idx, val);
        }
    }
}