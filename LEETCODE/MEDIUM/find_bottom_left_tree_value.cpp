#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    
    // 1st way
    int oppositeBFS(TreeNode* root ){
        queue<TreeNode*> q;
        q.push(root);
        int result = -1;
        while(!q.empty()){
            TreeNode* temp = q.front();
            result = temp->val;
            q.pop();
            
            // agar root ka right hai to usee queue me dalo then after root  ak left queue me dalo
            // jisse last value hoga o automatic root ka left hoga in result
            
            if(temp -> right) {
                q.push(temp->right);
            }
            if(temp -> left){
                q.push(temp -> left);
            }
        }
        return result;
    }
    
    
    
    // 2nd way
    int leftValue;
    int maxLevel;       
    void dfs(TreeNode* root, int currLevel){
        // we have to return maxlevel left most value
            if(!root) return;
            
            if(currLevel > maxLevel){
                maxLevel = currLevel;
                leftValue = root->val;
            }
            
            dfs(root -> left, currLevel + 1);
            dfs(root -> right, currLevel + 1);
    }
    
    
    int findBottomLeftValue(TreeNode* root) {
        
        maxLevel = -1;
        leftValue = -1;
        int currLevel = 0;
        dfs(root,currLevel);
        return leftValue;
        
        // return oppositeBFS(root);

    }
};


int main(){

}