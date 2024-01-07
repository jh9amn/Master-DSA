#include<iostream>
#include<stack>
using namespace std;

int operation(int val1,int val2,char s){
    if(s == '+') return val1+val2;
    else if(s == '-') return val1-val2;
    else if(s == '*') return val1*val2;
    else  return val1/val2;
}


int main(){
    string s = "79+4*8/3-";
    stack<int>val;
    for(int i=0; i<s.size(); i++){    // '0' == (Ascii)48 && '9' == (Ascii)57
        if(s[i] >= 48 && s[i] <= 57) val.push(s[i]-48);
        else{ 
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                int ans = operation(val1,val2,s[i]);
                val.push(ans);          
       }
    }
    cout<<val.top()<<endl;     // answer using postfix form
    cout<<(7+9)*4/8-3<<endl;   // infix form
}

