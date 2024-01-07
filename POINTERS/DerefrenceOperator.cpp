#include<iostream>
using namespace std;
int main(){
    int x = 100;
   int *p = &x;
cout<<x<<endl;
// now value of x is accesable by pointer p
cout<<*p<<endl;
 *p = 50;
cout<<x<<endl;   
cout<<*p<<endl;
}