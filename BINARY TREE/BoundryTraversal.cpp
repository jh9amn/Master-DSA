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


Node* construct (int arr[],int n){
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    int j = 2;

    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN)   l = new Node(arr[i]);  
        else l = NULL;
        if(j!=n && arr[j]!=INT_MIN)    r = new Node(arr[j]);  
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL)  q.push(l);
        if(r!=NULL)  q.push(r);

        i+=2;
        j+=2;
    }
    return root;
}

void leftBoundry(Node* root){   // 1 2 4 5 3 6 10
  if(root==NULL) return;
  if(root->left==NULL && root->right==NULL)  return;
  cout<<root->val<<" ";
  leftBoundry(root->left);
  if(root->left==NULL) leftBoundry(root->right);
} 

void bottomBoundry(Node* root){  
    if(root==NULL) return;     // 4 2 5 1 6 3 10
    if(root->left==NULL && root->right==NULL)  cout<<root->val<<" ";
    bottomBoundry(root->left);
    bottomBoundry(root->right);
} 

void rightBoundry(Node* root){     // 4 5 2 6 10 3 1
    if(root==NULL) return;     // 4 2 5 1 6 3 10
    if(root->left==NULL && root->right==NULL)  return;
    rightBoundry(root->right);
    if(root->right==NULL) rightBoundry(root->left);
    cout<<root->val<<" ";
} 


int main(){
int arr[] = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28};
int n = sizeof(arr)/sizeof(arr[0]);
Node* root = construct(arr,n);
    leftBoundry(root);
    bottomBoundry(root);
    rightBoundry(root->right);

}