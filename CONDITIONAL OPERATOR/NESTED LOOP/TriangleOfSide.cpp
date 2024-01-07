#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"enter the first";
    cin>>a;
    cout<<"Enter the second side";
    cin>>b;
    cout<<"enter the third side";
    cin>>c;

    if ((a+b>c) && (b+c>a) && (c+a>b)){
        cout<<a<<","<<b<<","<<c<<","<<"could be side of Triangle";
    }
    else {
        cout<<"Could Not be Side of Triangle";
    }
    

}