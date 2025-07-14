#include<bits/stdc++.h>
using namespace std;

    int arr[100005];
    // max node index in segment tree can be 4n;
    int seg[4 * 100005];

void build(int idx, int low, int high) {
    if(low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid);       // left index = 2*idx+1
    build(2 * idx + 2, mid + 1, high);  // right index = 2*idx+2
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);     // building segment tree array...
}

int query(int idx, int low, int high, int l, int r) {
    // completly lies in range return ans;
    // donot go futher..
    if(low >= l && high <=r) 
        return seg[idx];


    // if not in range
    if(high < l || low > r)
        return INT_MIN;

    // if overlap in left side or right side
    int mid = (low + high) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);

    return max(left, right);
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    build(0, 0, n-1);   // index, low, high

    int q;
    cin >> q;
    while(q--) {
        int l, r;       // ranges
        cin >> l >> r;
        cout <<"MAX element: "<< query(0, 0, n - 1, l, r)<<endl;
    }
}