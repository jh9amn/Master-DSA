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
    
    bool dfs(TreeNode* root){
        if(root -> left == NULL and root -> right == NULL) return root -> val;
        
        bool a =  dfs(root -> left);
        bool b =  dfs(root -> right);
        
        if(root-> val == 2) return a or b;
        else return a and b;   
    }
    
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};

int main(){

}