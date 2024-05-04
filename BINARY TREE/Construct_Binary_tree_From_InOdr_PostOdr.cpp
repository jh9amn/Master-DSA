#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     TreeNode* tree(vector<int> &in,int inlo, int inhi, vector<int>&post,int postlo,int posthi){
        if(postlo > posthi) return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        if(postlo == posthi) return root;
        int i = inlo;
        while(i < inhi){
        if(post[posthi] == in[i]) break;  
            i++;
        } 
        int leftCount = i-inlo; 
        int rightCount = inhi - i;
        root->left = tree(in,inlo,i-1,post,postlo,postlo+leftCount-1);
        root->right = tree(in,i+1,inhi,post,postlo+leftCount,posthi-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n  = inorder.size();
        return tree(inorder,0,n-1,postorder,0,n-1);
    }
};

int main(){


}