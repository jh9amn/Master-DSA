//  Making even index  elements 'o'

#include<iostream>
#include<string>
using namespace std;
 int main(){

string str = "Aman";

cout<<str<<endl;

for(int i=0; str[i]!='\0'; i++){
    if(i%2==0) str[i] = 'o';
}

cout<<str<<endl;


 }