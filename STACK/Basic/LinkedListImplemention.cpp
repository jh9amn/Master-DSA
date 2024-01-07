#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{     //user define data type
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Stack{
public:
    Node* head;
    int size;

    Stack(){
        head = NULL;
        size = 0;
    }

    void push(int val){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void top(){
        if(head == NULL) {
            cout<<"Stack is Empty "<<endl;
            return;
        }
        head = head->next;
        cout<<head->val<<endl;
        size--;
    }

    int pop(){
        if(head == NULL) {
            cout<<"Stack is Empty "<<endl;
            return -1;
        }
        return head->val;
    }

    void displayReverse(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void print(Node* temp){
        if(temp == NULL) return;
        print(temp->next);
        cout<<temp->val<<" ";
    }

    void display(){
        Node* temp = head;
        print (temp);
        cout<<endl;
    } 
};


int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    s.displayReverse();
    s.top();
    cout<<s.size<<endl;
    cout<<s.pop()<<endl;
    s.display();
}