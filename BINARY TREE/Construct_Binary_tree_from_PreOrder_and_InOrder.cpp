#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* tree(vector<int> &pre,int prelo,int prehi,vector<int> &in,int inlo, int inhi){
        if(prelo>prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo == prehi) return root;
        int i = inlo;
        while(i < inhi){
            if(pre[prelo] == in[i]){ break;  
              i++;
            }
            else i++; 
            }
        int leftCount = i-inlo; 
        int rightCount = inhi - i;
        root->left = tree(pre,prelo+1,prelo+leftCount,in,inlo,i-1);
        root->right = tree(pre,prelo+leftCount+1,prehi,in,i+1,inhi);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n  = preorder.size();
        return tree(preorder,0,n-1,inorder,0,n-1);
    }
};


int main(){

}