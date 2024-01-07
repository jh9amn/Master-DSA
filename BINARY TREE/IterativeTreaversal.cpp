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

void preOrder(Node* root){   // 1 2 4 5 3 6 10
    stack<Node*> st;
    if(root!=NULL) st.push(root);
    while(st.size()>0){
        Node* temp = st.top();
        st.pop();
        cout<<temp->val<<" ";
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left); 
    }
} 

void inOrder(Node* root){       // 4 2 5 1 6 3 10
    stack<Node*> st;
    Node* node = root;
    while(st.size()>0 || node!=NULL){
       if(node!=NULL){   //if(node) = if(node!=NULL)
        st.push(node);
        node = node->left;
       }   
       else {
        Node* temp = st.top();
        st.pop();
        cout<<temp->val<<" ";
        node = temp->right;
       }
    }   
} 

void postOrder(Node* root){     // 4 5 2 6 10 3 1
    stack<Node*> st;
   stack<int> helper;
    if(root!=NULL) st.push(root);
    while(st.size()>0){
        Node* temp = st.top();
        st.pop();
        helper.push(temp->val);   // ROOT RIGHT LEFT
        if(temp->left!=NULL) st.push(temp->left); 
        if(temp->right!=NULL) st.push(temp->right);
    }

    // LEFT RIGHT ROOT
    while(helper.size()!=0){
        cout<<helper.top()<<" ";
        helper.pop();
    }
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
    // cout<<"Size :"<<size(a)<<endl;
    // cout<<"Max :"<<maxi(a)<<endl;
    // cout<<"Min :"<<mini(a)<<endl;
    //  cout<<"Level :"<<level(a)<<endl;
    // cout<<"product :"<<product(a)<<endl;

    preOrder(a);
       cout<<endl;
    inOrder(a);
       cout<<endl;
    postOrder(a);

}