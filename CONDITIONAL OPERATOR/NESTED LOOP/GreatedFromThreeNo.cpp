#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"enter the first number"<<" ";
    cin>>a;
    cout<<"enter the secomd number"<<" ";
    cin>>b;
    cout<<"enter the third number"<<" ";
    cin>>c;

    if(a>b){
        if(a>c){
            cout<<a<<" is greater";
        }
        else{  //a>b ,  c>a , c>a>b
            cout<<c<<" is greater";
        }
    }  else{  // b>a
        if(b>c){
            cout<<b<<" is greater";
        }
        else {  // b>a , c>b , c>b>a
        cout<<c<<" is greater";
        }
    }
    return 0;
}