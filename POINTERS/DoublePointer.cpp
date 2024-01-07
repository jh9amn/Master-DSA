#include<iostream>
using namespace std;
int main(){
    int x = 5;
    int *ptr = &x;
    int **p = &ptr;
    int ***q = &p;

    cout<<x<<endl;      //5
    cout<<*ptr<<endl;   //5
    cout<<**p<<endl;    //5
    cout<<***q<<endl;   //5
    cout<<&x<<endl;    //0x61ff08
    cout<<ptr<<endl;   //0x61ff08
    cout<<*p<<endl;    //0x61ff08
    cout<<**q<<endl;   //0x61ff08
}