//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    

    Node* tree(int in[],int inlo, int inhi, int post[],int postlo,int posthi){
        if(postlo > posthi) return NULL;
        Node* root = new    Node(post[posthi]);
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
    
    Node *buildTree(int in[], int post[], int n) {
        return tree(in,0,n-1,post,0,n-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends