#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int prio(char s){
    if(s == '/' || s == '*') return 2;
    else return 1;
}

string solve(string val1, string val2,char ch){
    string sh = "";
    sh += val1;
    sh += val2;
    sh.push_back(ch);
    return sh;
}

int main(){
    string s = "(7+9)*4/8-3";
    stack<string> val;
    stack<char> op;
    for(int i=0; i<s.length(); i++){    // '0' == (Ascii)48 && '9' == (Ascii)57
        if(s[i] >= 48 && s[i] <= 57) val.push(to_string(s[i]-48));
        else{
            if(op.size()==0)  op.push(s[i]);
            else if(s[i] == '(') op.push(s[i]);
            else if(op.top() == '(') op.push(s[i]);
            else if(s[i] == ')'){   // work
                while(op.top() != '('){
                string val2 = val.top();
                val.pop();
                string val1 = val.top();
                val.pop();
                string ans = solve(val1,val2,op.top());
                op.pop();
                val.push(ans);
            }   op.push(s[i]);
            }
            else if(prio(s[i]) > prio(op.top())) op.push(s[i]);
            else{  // prio(s[i] <= prio(op.top()))
                while(op.size()>0 && prio(s[i]) <= prio(op.top())){
                string val2 = val.top();
                val.pop();
                string val1 = val.top();
                val.pop();
                string ans = solve(val1,val2,op.top());
                op.pop();
                val.push(ans);
            }   op.push(s[i]);
          }
       }
    }

    while(op.size()>0){
                string val2 = val.top();
                val.pop();
                string val1 = val.top();
                val.pop();
                string ans = solve(val1,val2,op.top());
                op.pop();
                val.push(ans);
    }
    cout<<val.top()<<endl; 
}

