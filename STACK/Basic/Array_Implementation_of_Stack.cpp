#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
class Stack{
public:
    int arr[5];
    int idx;

    Stack(){
        idx = -1;
    }

    void push(int val){
        if(idx == 4){
            cout<<"Stack is Full";
            return;
        }
        idx++;
        arr[idx] = val;
    }


    int top(){
        if(idx == -1){
            cout<<"Stack is enpty"<<endl;
            return idx;
        }
        return arr[idx];
    }

    int pop(){
        if(idx == -1) {
            cout<<"Stack Is Empty";
            return idx;
        }
        return idx--;
    }

    int size(){
        return idx+1;
    }

    void display(){
        if(idx == -1) {
            cout<<"Empty stack"<<endl;
            return;
        }
        cout<<"The Stack Is as : ";
        for(int i=0; i<=idx; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void minEle(){
        if(idx == -1) {
            return;
        }
        int mini = INT_MAX;
        for(int i=0; i<=idx; i++){
            mini = min(arr[i], mini);
        }
        cout<<"Minimum Element in stack is : ";
        cout<<mini<<endl;
    }


};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.minEle();
    s.display();
    cout<<"The top Element is : "<<s.top()<<endl;
    s.pop();
    cout << "Stack is poped "<<endl;
    s.display();
    return 0;
}
