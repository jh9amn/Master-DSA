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

int size(Node* root){
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right) ;
}

int sum(Node* root){
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right) ;
}

int product(Node* root){
    if(root == NULL) return 1;
    return root->val * product(root->left) * product(root->right) ;
}

int maxi(Node* root){
    if(root == NULL) return INT_MIN;
    return max(root->val, max(maxi(root->left) , maxi(root->right))  ) ;
}

int level(Node* root){
    if(root == NULL) return 0;
    return 1 + max(level(root->left) , level(root->right))  ;
}

int mini(Node* root){
    if(root == NULL) return INT_MAX;
    return min(root->val, max(mini(root->left) , mini(root->right))  ) ;
}

void preOrder(Node* root){      // ROOT LEFT RIGHT
   if(root == NULL) return ;
   cout<<root->val<<" ";
   preOrder(root->left);
   preOrder(root->right);
} 

void inOrder(Node* root){       // LEFT ROOT RIGHT
   if(root == NULL) return ;
   inOrder(root->left);
   cout<<root->val<<" ";
   inOrder(root->right);
} 

void postOrder(Node* root){     // LEFT RIGHT ROOT
   if(root == NULL) return ;
   postOrder(root->left);
   postOrder(root->right);
   cout<<root->val<<" ";
   
} 


int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(10);
    // Node* h = new Node(100);


    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    // f->left = h;
    
    // cout<<"Elements : ";
    // cout<<endl;
    // cout<<"Sum :"<<sum(a)<<endl;
    cout<<"Size :"<<size(a)<<endl;
    cout<<"Max :"<<maxi(a)<<endl;
    cout<<"Min :"<<mini(a)<<endl;
    //  cout<<"Level :"<<level(a)<<endl;
    // cout<<"product :"<<product(a)<<endl;

    preOrder(a);
       cout<<endl;
    inOrder(a);
       cout<<endl;
    postOrder(a);
}