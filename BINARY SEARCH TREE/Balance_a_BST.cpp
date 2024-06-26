#include<bits/stdc++.h>
using namespace std;
int main(){}



class Solution {
public:
    void inorder(TreeNode* root, vector<int> &sortedArray){
        if(!root) return;
        
        inorder(root -> left, sortedArray);
        sortedArray.push_back(root-> val);
        inorder(root -> right, sortedArray);
    }
    
    TreeNode* ConstructBalanceBST(int l, int r, vector<int> &sortedArray){
        
        if(l > r) return NULL;
        
        int mid = l + (r-l)/2;
        
        // find mid then start recursion which will add left to root left part of array and right to root right part of array
        
        TreeNode* root = new TreeNode(sortedArray[mid]); 
        root -> left = ConstructBalanceBST(l, mid-1, sortedArray);
        root -> right = ConstructBalanceBST(mid+1, r, sortedArray);
        
        return root;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedArray;
        inorder(root, sortedArray);
        
        int n = sortedArray.size();
        
        return ConstructBalanceBST(0, n-1, sortedArray);
    }
};