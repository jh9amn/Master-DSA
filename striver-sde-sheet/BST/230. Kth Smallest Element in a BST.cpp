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
private: 
    int ans;
public:
    void dfs(TreeNode* root, int &k) {
        if(root == NULL) return;


        dfs(root -> left, k);

        k--;
        if(k == 0) {
            ans = root -> val;
            return;
        }

        dfs(root -> right, k);

    }


    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};


class Solution {
private: 
    void dfs(TreeNode* root, vector<int> &ans) {
        if(!root) return;

        dfs(root -> left, ans);

        ans.push_back(root -> val);

        dfs(root -> right, ans);
    }


public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root, ans);
        return ans[k-1];
    }
};
