#include<iostream>
#include<stack>
using namespace std;

int operation(int val1,int val2,char s){
    if(s == '+') return val1+val2;
    else if(s == '-') return val1-val2;
    else if(s == '*') return val1*val2;
    else  return val1/val2;
}

int prio(char s){
    if(s == '/' || s == '*') return 2;
    else return 1;
}

int main(){
    string s = "2+6*4/8-3";
    stack<int>val;
    stack<char> op;
    for(int i=0; i<s.size(); i++){    // '0' == (Ascii)48 && '9' == (Ascii)57
        if(s[i] >= 48 && s[i] <= 57) val.push(s[i]-48);
        else{
            if(op.size()==0)  op.push(s[i]);
            else if(prio(s[i]) > prio(op.top())) op.push(s[i]);
            else{  // prio(s[i] <= prio(op.top()))
                while(op.size()>0 && prio(s[i]) <= prio(op.top())){
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                int ans = operation(val1,val2,op.top());
                op.pop();
                val.push(ans);
            } op.push(s[i]);
          }
       }
    }

    while(op.size()!=0){
               int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                int ans = operation(val1,val2,op.top());
                op.pop();
                val.push(ans);
    }
    cout<<val.top()<<endl; 

}

