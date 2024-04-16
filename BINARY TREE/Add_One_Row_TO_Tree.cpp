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
    // T.C = O(n)   S.C = (1)
    void dfs(TreeNode* root, int val, int depth, int level){
        if(root == NULL) return;
        
        if(level == depth - 1){
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            
            newLeft -> left = root -> left;
            newRight -> right = root -> right;
            
            root -> left = newLeft;
            root -> right = newRight;
        }
        
        dfs(root -> left, val, depth, level +1);
        dfs(root -> right, val, depth, level + 1);
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }
        
        dfs(root, val, depth, 1);
        
        return root;
    }
};



int main(){

}