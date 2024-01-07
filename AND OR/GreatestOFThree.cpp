#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"enter the first number";
    cin>>a;
    cout<<"enter the second number";
    cin>>b;
    cout<<"enter the third number";
    cin>>c;

    if(a>b && a>c){
        cout<<"first number is greater :"<<a;
    }
    if(b>a && b>c){
        cout<<"second number is greater :"<<b;         
    }
    if(c>a && c>b){
        cout<<"third number is greater :"<<c;
    }
}