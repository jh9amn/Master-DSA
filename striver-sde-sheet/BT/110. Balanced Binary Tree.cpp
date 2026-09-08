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
    // find height from particular node
    // O(n)
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root -> left), height(root -> right)); 
    }

    // O(n*n)
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftH = height(root -> left);
        int rightH = height(root -> right);

        if(abs(leftH - rightH) > 1) return false;

        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};


// Optimized 
class Solution {
private:
    // O(n)
    int checkingHeight(TreeNode* root) {
        if(root == NULL) return 1;

        int leftH = checkingHeight(root -> left);
        if(leftH == -1) return -1;

        int rightH = checkingHeight(root -> right);
        if(rightH == -1) return -1;

        if(abs(leftH - rightH) > 1) return -1;

        return 1 + max(leftH, rightH);
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkingHeight(root) != -1;
    }
};
