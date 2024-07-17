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

    TreeNode* dfs(TreeNode* root, unordered_set<int> &st, vector<TreeNode*> &ans){
        if(root == NULL){
            return NULL;
        }

        root -> left = dfs(root -> left, st, ans);
        root -> right = dfs(root -> right, st, ans);


        // Process Root Now  (LRU) -> left , right, root

        // Not to be deleted
        if(!st.count(root -> val)){
            return root;
        }

        // to be deleted
        if(root -> left != NULL) {
            ans.push_back(root -> left);
        }

        if(root -> right != NULL) {
            ans.push_back(root -> right);
        }

        root -> left = NULL;
        root -> right  = NULL;

        return NULL;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(auto x : to_delete){
            st.insert(x);
        }

        vector<TreeNode*> ans;

        root = dfs(root, st, ans);

        if(root != NULL){
            ans.push_back(root);
        }
        
        return ans;
    }
};