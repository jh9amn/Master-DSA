#include<iostream>
#include<string>
using namespace std;
 int main(){
    string str = " Aman kumar Jha";
    cout<<str;
    cout<<endl;
    // taking input in string

    string s;
    // cin>>s;  // it takes space as the next line
    // cout<<s;

    getline(cin,s);  // it is used to take full sentences etc..
    cout<<s;
    return 0;
 }