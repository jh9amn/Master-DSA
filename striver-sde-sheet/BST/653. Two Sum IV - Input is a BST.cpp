/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tiii = tuple<int, int, int>;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
#define pb push_back

void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


// TC = O(n) SC = O(n)
class Solution {
public:
    void inorder(TreeNode* root, vi &store) {
        if(root == NULL) return;
        
        inorder(root -> left, store);
        store.pb(root -> val);
        inorder(root -> right, store);
    }
    bool findTarget(TreeNode* root, int k) {
        vi store;
        inorder(root, store);

        int l = 0;
        int r = store.size()-1;
        while (l < r) {
            if(store[l] + store[r] == k) return true;
            else if(store[l] + store[r] > k) r--;
            else l++;
        }
        return false;
    }
};

// Using Binary Iterator
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
    }
};
