#include<iostream>
using namespace std;
void sum(int s, int n){
     if(n==0) {
        cout<<s<<endl;
        return;
     }
     sum(s+n,n-1);
}

// like factorial
int sum2(int n){
    if(n==0)  return 0;
    return n+sum2(n-1);
}

 int main(){
sum(0,4);
cout<<sum2(10);
 }
    