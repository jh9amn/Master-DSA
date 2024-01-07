// NUMBER OF WAY OF n FRIENDS GO TO THE PARTY IN PAIR OF 2 OR 1  

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f(int n){
    if(n==1 || n==2) return n;
    return f(n-1) + (n-1)*f(n-2);
}
 int main(){
    cout<<f(3);
 }