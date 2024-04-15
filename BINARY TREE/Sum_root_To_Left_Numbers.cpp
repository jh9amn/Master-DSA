#include<bits/stdc++.h>
using namespace std;

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
    // T.C = O(n)   S.C = O(n)
    int ans;
    void dfs(TreeNode* root, int sum){
        if(root == NULL) {
            return;
        }
        
        sum = 10 * sum + root -> val;
        if(root -> left == NULL and root -> right == NULL) {
            ans += sum;
            return;
        }
        
        dfs(root -> left, sum);

        dfs(root -> right, sum);
        
        
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root,0);
        return ans;
    }
};


int main(){

}