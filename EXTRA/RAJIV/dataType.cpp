#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s=="Interger") cout<<"4 bytes";
    else if(s=="Float") cout<<"4 bytes";
    else if(s=="Double") cout<<"8 bytes";
    else if(s=="Long") cout<<"8 bytes";
    else cout<<"1 bites"; 
}