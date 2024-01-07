#include<iostream>
using namespace std;
int main(){
    int n,count=0;
    cout<<"Enter the number";
    cin>>n;
    int a=n;
    while (n>0){
        n = n/10;
        count ++;
    }
    if(a==0)  cout<<1;
    else      cout<<count;

}