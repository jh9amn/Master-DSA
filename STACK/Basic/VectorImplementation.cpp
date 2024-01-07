#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack{
public:
vector<int> v;     // no  overFlow condition

void push(int val){
  v.push_back(val);
}

int top(){
    if(v.size() == 0){
        cout<<"Empty Stack "<<endl;
        return -1;
    }
    return v[v.size()-1];
}

int size(){
    return v.size();
}

void pop(){
    if(v.size() == 0){
        cout<<"Empty Stack "<<endl;
        return;
    }
    v.pop_back(); 
}

void display(){
    if(v.size() == 0){
        cout<<"Empty Stack"<<endl;
        return;
    }
    for(int i=0; i<=v.size()-1; i++){
        cout<<v.at(i)<<" ";
    }
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
    
    s.display();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    s.display();
}