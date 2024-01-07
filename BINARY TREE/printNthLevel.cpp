    // PRINT THE ELEMENTS OF 3RD LEVEL OF THE TREE

/*
         1           1st Level Elements
        / \
       /   \
      2     3        2nd Level Elements
     /\     /\
    /  \   /  \
   4    5  6   7     3rd Level Elements

*/

#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this ->val = val;
        this ->left = NULL;
        this ->right = NULL;
    }
};

int level(Node* root){
    if(root==NULL) return 0;
    return 1+max(level(root->left), level(root->right));
}

void nthLevel(Node* root, int currLevel , int level){
   if(root == NULL) return ;
   if(currLevel == level){
     cout<<root->val<<" ";
     return;
   }
   nthLevel(root->left,currLevel+1,level);
   nthLevel(root->right,currLevel+1,level);  
} 


void levelOrder(Node* root){
    if(root == NULL) return;
    int n = level(root);
    for(int i=1; i<=n; i++){
        nthLevel(root,1,i);
        cout<<endl;
    }
}

//  THIS IS USED TO PRINT THE ELEMENT OF THE NTH LEVEL INTO THE REVERSE ORDER LIKE RIGHT TO LEFT
void nthLevelReverse(Node* root, int currLevel , int level){
   if(root == NULL) return ;
   if(currLevel == level){
     cout<<root->val<<" ";
     return;
   }
    nthLevelReverse(root->right,currLevel+1,level);  
    nthLevelReverse(root->left,currLevel+1,level);
} 

//   level of order using QUEUE
void levelOrderQueue(Node* root){    // BFS (breath first Search) technique
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }cout<<endl;
}




int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);


    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    // int currLevel = 1;
    // int level = 3;

    // nthLevel(a,currLevel,level);
    // cout<<endl;
    // levelOrder(a);
    levelOrderQueue(a);
}
