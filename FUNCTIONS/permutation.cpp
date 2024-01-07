//PERMUTATION  = n!/(n-r)!

#include<iostream>
using namespace std;
int factorial(int x){
     int fact = 1;
    for (int i=1; i<=x; i++){  
        fact = fact * i;   
    }
        return fact;   
}

int permutation(int a, int b){
    int comb = factorial(a)/factorial(a-b);
    return comb;

}

int main(){
    int n;
    cout<<"Enter the n ";
    cin>>n;
    int r;
    cout<<"Enter the Value of r ";
    cin>>r;
    // int nfact = factorial(n);
    // int nrfact = factorial(n-r);
    int pnr = permutation (n,r);
   
    cout<<"PERMUTATION = "<< pnr;

}