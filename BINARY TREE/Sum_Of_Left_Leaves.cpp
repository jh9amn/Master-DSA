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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        int sum = 0;
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int val = q.front().second;
            
            if(val == 1){
                if(temp -> left == NULL and temp -> right == NULL){
                    sum += temp -> val;
                }
            }
            
            q.pop();
            if(temp -> left != NULL) q.push({temp -> left,1});
            if(temp -> right != NULL) q.push({temp -> right,0});
        }
        return sum;
    }
};



int main(){


}