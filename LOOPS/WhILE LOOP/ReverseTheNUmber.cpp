#include<iostream>
using namespace std;
int main(){
    int n,lastdigit = 0,reverse = 0;
    cout<<"Enter the Number";
    cin>>n;
    while(n>0){
        reverse *= 10;
        lastdigit = n%10;
        reverse += lastdigit;
        n/=10;
    }cout<<reverse;

}