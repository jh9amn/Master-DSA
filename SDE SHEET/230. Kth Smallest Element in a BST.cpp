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
    void inorder(TreeNode* root, int& count, int& ans, int& k){

        if(!root || ans != -1){
            return;
        }

        inorder(root -> left, count, ans, k);

        count++;

        if(count == k){
            ans = root -> val;
            return;
        }

        inorder(root -> right, count, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        inorder(root, count, ans, k);
        return ans;
    }
};
