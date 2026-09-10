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

using vi = vector<int>;

/* Naive approach

TC = O(n) + nlog(n) + O(n)  ~ nlog(n)
Sc = O(h) + O(n) + O(h)     ~ O(n)

*/
class Solution {
private: 
    
    // O(n)
    void dfs(TreeNode* root, vi &inorder) {
        if(!root) return;

        dfs(root -> left, inorder);

        inorder.push_back(root -> val);

        dfs(root -> right, inorder); 
    }

    // O(n)
    void dfsFix(TreeNode* root, vi &inorder, int &i) {
        if(!root) return;

        dfsFix(root -> left, inorder, i);

        if(root -> val != inorder[i]) {
            root -> val = inorder[i];
        }

        i++;

        dfsFix(root -> right, inorder, i); 
    }

public:
    void recoverTree(TreeNode* root) {
        vi inorder;

        dfs(root, inorder);

        // nlog(n)
        sort(begin(inorder), end(inorder));


        int i = 0;
        dfsFix(root, inorder, i);
        
    }
};




/*

## Swaps can have two cases

1) Swapped nodes are not adjecent
    3 25 7 8 10 15 20 5   -> nodes 5 & 25

    so there is two voilation
    first voilation - 25
    mid - 7
    second voilation - 5 

    if we got second voilation then (first, second);    


2) swapped nodes are adjecent
    3 5 8 7 10 15 20 25  -> nodes 7 & 8

    but here only one voilation

    first voilation - 8
    mid - 7 
    second voilation - NULL

    if we got only one voilation then swap(first, mid)

*/


// O(n) time
// O(h) space
using tn = TreeNode*;
class Solution {
private: 
    void dfs(tn root, tn &prev, tn &first, tn &mid, tn &second) {
        if(!root) return;

        dfs(root -> left, prev, first, mid, second);

        // Violation found
        if(prev != NULL and (root -> val < prev -> val)) {
            // First violation
            if (first == NULL) {
                first = prev;
                mid = root;
            }

            // Second violation
            else {
                second = root;
            }
        }
        
        prev = root;
        dfs(root -> right, prev, first, mid, second);
    }

public:
    void recoverTree(TreeNode* root) {
        tn prev = NULL;
        tn first = NULL;
        tn mid = NULL;
        tn second = NULL;

        dfs(root, prev, first, mid, second);

        if(first && second) swap(first -> val, second -> val);
        else if(first and mid) swap(first -> val, mid -> val);
    }
};

