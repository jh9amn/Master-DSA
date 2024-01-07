#include<iostream>
using namespace std;
int fact(int n){
    if(n==1 || n==0) return 1;
     return (n*fact(n-1));  

}

int main(){
    cout<<"Enter the Number";
    int n;
     cin>>n;
    int a = fact(n);
    cout<<a;
}

// FActorial OF N = n *(n-1)!