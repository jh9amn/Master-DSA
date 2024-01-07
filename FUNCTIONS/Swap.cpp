#include<iostream>
using namespace std;
int main(){
    int a, b;
    cout<<"Enter two Numbers";
    cin>>a>>b;

    // int temp;
    //  temp =a;
    //  a=b;
    //  b = temp;
    //  cout<<a<<" "<<b;
    //  return 0;


    //Another Merhod

    a = a + b;
    b = a - b;
    a = a - b;
    cout<<a<<" "<<b;
}