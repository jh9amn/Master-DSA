#include<iostream>
using namespace std;
void num(int i, int n){
    if(i>n) return;
    cout<<i<<"\n";
    num(i+1,n);
}
int main(){
    int  n;
    cout<<"n ";
    cin>>n;
    num(1,n);
}
