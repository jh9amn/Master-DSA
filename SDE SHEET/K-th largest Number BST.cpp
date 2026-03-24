#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

/* https://www.naukri.com/code360/problems/k-th-largest-number_920438?leftPanelTabValue=PROBLEM */

void reverseInorder(TreeNode<int>* root, int k, int& ans, int &count){
    if(!root || ans != -1){
        return;
    }

    // reverse inoder traversal
    reverseInorder(root -> right, k, ans, count);

    count++;

    if(count == k){
        ans = root -> data;
        return;
    }

    reverseInorder(root -> left, k, ans, count);
}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    int count = 0;
    reverseInorder(root, k, ans, count);
    return ans;
}
