#include<bits/stdc++.h>
using namespace std;
int main(){}

/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified tree after removing all the half nodes.
class Solution {
  public:
    Node* dfs(Node* root){
        if(root == NULL ) return NULL;

        root-> left = dfs(root -> left);
        root -> right = dfs(root -> right);
        
        if(root -> left == NULL and root -> right){
            return root -> right;
        }
        
        if( root -> right == NULL and root -> left){
            return root -> left;
        }
        
        return root;
    }
    
    Node *RemoveHalfNodes(Node *root) {
        return dfs(root);
    }
};