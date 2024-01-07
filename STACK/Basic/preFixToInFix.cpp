#include<iostream>
#include<stack>
using namespace std;

string operation(string val1,string val2,char s){
string sh = "";
sh += val1;
sh.push_back(s);
sh += val2;
return sh;
}


int main(){
    string s = "-/*+79483";
    stack<string>val;
    for(int i=s.size()-1; i>=0; i--){    // '0' == (Ascii)48 && '9' == (Ascii)57
        if(s[i] >= 48 && s[i] <= 57) val.push(to_string(s[i]-48));
        else{ 
                string val1 = val.top();
                val.pop();
                string val2 = val.top();
                val.pop();
                string ans = operation(val1,val2,s[i]);
                val.push(ans);          
       }
    }
    cout<<val.top()<<endl;     // answer using postfix form
    //  (7+9)*4/8-3   infix form
}

