#include<bits/stdc++.h>
#include<string>
using namespace std;
void f(string str,string s){
    if(str.length () == 0) {
        cout<<s<<" ";
        return;
    }
    char ch = str[0];
    if(ch == 'a') f(str.substr(1), s);
    else f(str.substr(1), s+ch);
}

// another way to skip
void f2(string &str,string s,int i){
    if( i== str.size()){
        cout<<s;
        return;
    }
    if(str[i] == 'a') f2(str,s,i+1);
    else f2(str,s+str[i],i+1);
}

int main(){
    string str = "aman kumar";
    string s = "";

    // for(int i=0; i<str.size(); i++){
    //     if(str[i] != 'a') s+=str[i];
    // }cout<<s;

    f(str,s);

    f2(str,s,0);
}