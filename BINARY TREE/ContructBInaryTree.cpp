#include<iostream>
#include<algorithm>
#include<queue>
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

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = construct(arr,n);
    
    levelOrder(root);
    cout<<endl;
    levelOrderQueue(root);
}
