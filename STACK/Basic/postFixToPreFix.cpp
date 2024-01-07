#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

string operation(string val1,string val2,char ch){
string s = "";
s.push_back(ch);
s += val1;
s += val2;
return s;
}

int main(){
    string s = "79+4*8/3-";   //postfix
    stack<string>val;
    for(int i=0; i<s.size(); i++){    // '0' == (Ascii)48 && '9' == (Ascii)57
        if(s[i] >= 48 && s[i] <= 57) val.push(to_string(s[i]-48));
        else{ 
                string val2 = val.top();
                val.pop();
                string val1 = val.top();
                val.pop();
                string ans = operation(val1,val2,s[i]);
                val.push(ans);          
       }
    }
    cout<<val.top()<<endl;     // answer using postfix form
}