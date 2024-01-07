#include<iostream>
using namespace std;
void Function(int n){
    if(n==0) return;
    else {
        cout<<"Good Morning"<<endl;
    }
    Function(n-1);
}
int main(){
    cout<<"N";
    int n;
    cin>>n;
    Function(n);
}
