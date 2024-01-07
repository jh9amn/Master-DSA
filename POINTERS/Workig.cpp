#include<iostream>
using namespace std; 
int main(){
    int x;
    int *p = &x; //storing address of x

    //the address is same 
    cout<< p <<endl;
    cout<<&x;
}