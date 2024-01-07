#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main(){

    // used to convert string to Integer
    string s = "1234567";
    int x = stoi(s);
    cout<<x+1<<endl;

    // Used to convert interger tO String
    int y = 123456;
    string ss = to_string(y);
    cout<<ss<<" "<<"Length"<<ss.length()<<endl;

    // Used To convert or Store String To Long long Datatype
    string z = "12344565896046";
    long long xx = stoll(z);
    cout<<"String Into long Long datatype "<<xx<<endl;


}