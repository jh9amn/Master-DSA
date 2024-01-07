#include<iostream>
#include<stack>
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

    int pop(){
        if(idx == -1) {
            cout<<"Stack Is Empty";
            return idx;
        }
        return idx--;
    }

    int top(){
        if(idx == -1){
            cout<<"Stack is enpty"<<endl;
            return idx;
        }
        return arr[idx];
    }

    int size(){
        return idx+1;
    }

    void display(){
        if(idx == -1) {
            cout<<"Empty stack"<<endl;
            return;
        }
        for(int i=0; i<=idx; i++){
            cout<<arr[i]<<" ";
        }
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
    cout<<s.pop()<<endl;
    s.display();
    return 0;
}
