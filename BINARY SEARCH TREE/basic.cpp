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


int main(){
    // BST
    Node* a = new Node(4);
    Node* b = new Node(3);
    Node* c = new Node(8);
    Node* d = new Node(2);
    Node* e = new Node(1);
    Node* f = new Node(7);
    Node* g = new Node(10);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
}