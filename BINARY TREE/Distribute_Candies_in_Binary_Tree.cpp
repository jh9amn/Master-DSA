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
    
    int dfs(TreeNode* root, int &moves){
        if(root == NULL) return 0;
        
        int l = dfs(root -> left, moves);
        int r = dfs(root -> right, moves);
        
        // agar root ka val 0 hai to usee 1  chahiye
        moves += abs(l) + abs(r);
        
        // ek use karo aur extra return to your parents.
        return (l + r + root -> val) - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};


int main(){

}