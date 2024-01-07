#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void permutation(string &s, int i){
    if(i == s.size()-1){
        cout<<s<<" ";
        return;
    }
    for(int ii= i; ii<s.size(); ii++){
        swap(s[i] , s[ii]);
        permutation(s,i+1);
        swap(s[i] , s[ii]);
    }
}

int main(){
    string str = "abc";
        permutation(str,0);
}