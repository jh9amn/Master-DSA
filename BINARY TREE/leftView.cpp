#include<iostream>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
/*       1           1st Level Elements
        / \
       /   \
      2     3        2nd Level Elements
     /\     /\
    /  \   /  \
   4    5  6   7     3rd Level Elements
*/
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

void leftView(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        int n = q.size();
        for(int i=1; i<=n; i++){
            Node* temp = q.front();
            q.pop();
            if(i == 1) cout<<temp->val<<" ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
}

    vector<int> leftViewUsingPreorder(Node* root, vector<int> &ans,int level){
        if(root == NULL) return ans;
            if (ans.size() == level ) ans.push_back(root->val);     // 1 2 4
            leftViewUsingPreorder(root->left,ans,level+1);
            leftViewUsingPreorder(root->right,ans,level+1);
            return ans;
    }


    vector<int> rightViewUsingPreorder(Node* root, vector<int> &ans,int level){
        if(root == NULL) return ans;
            ans[level] = root->val;   // 1 3 7  
            rightViewUsingPreorder(root->left,ans,level+1);
            rightViewUsingPreorder(root->right,ans,level+1);
            return ans;
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

    // leftView(a);
    vector<int> ans;
    cout<<"right view :";
    leftViewUsingPreorder(a,ans,0);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    cout<<"right view :";
    rightViewUsingPreorder(a,ans,0);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}