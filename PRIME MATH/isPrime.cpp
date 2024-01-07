#include<iostream>
#include<cmath>
using namespace std;
int fac = 0;
bool isPrime(int n){
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0)
        {
        fac = i;
        return false; 
        } 
    }
    return true;  
}
void  printFactor(int n){
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0) {
            cout<<i<<" ";
            if(i!=sqrt(n)) 
            cout<<n/i<<" ";
        }
    }
}

void  printFactor2(int n){
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0) {
            cout<<i<<" ";
    }
    }
    for(int i=sqrt(n)-1; i>=1; i--){
        if(n%i==0) {
            cout<<n/i<<" ";
    }
}
}

 int main(){
//  cout<<isPrime(35)<<endl;
//  cout<<fac;
 printFactor2(49);

 }