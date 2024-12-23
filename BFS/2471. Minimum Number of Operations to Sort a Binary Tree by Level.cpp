#include<bits/stdc++.h>
using namespace std;
int main(){}

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
class Solution {
public:
// w = max  of node at one level
// tc = level * wlog(w) + w + w
    int minimumOperations(TreeNode* root) {
        // level order traversal
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> a;
            unordered_map<int, int> mp;
            int i = 0;
            while(n--){
                TreeNode* temp = q.front();
                mp[temp -> val] = i;
                a.push_back(temp -> val);
                i++;
                q.pop();

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            vector<int> b = a;
            sort(begin(b), end(b));
            for(int i=0; i<b.size()-1; i++){
                if(b[i] != a[i]) {
                    int currIdx = mp[b[i]];
                    mp[a[i]] = currIdx;
                    mp[a[currIdx]] = i;
                    swap(a[i], a[currIdx]);
                    ans++;
                }
            }
        }
        return ans;
    }
};