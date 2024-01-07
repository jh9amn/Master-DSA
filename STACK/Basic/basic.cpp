#include<iostream>
#include<stack>
using namespace std;

void display(stack<int> st){
    stack<int> temp;
    while(st.size()>0){
        temp.push(st.top());
        // cout<<temp.top()<<" ";
        st.pop();
    }
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }                                                                                                                                                                                                                                                                                                              )
}

int main(){
    stack<int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);

    display(a);
}