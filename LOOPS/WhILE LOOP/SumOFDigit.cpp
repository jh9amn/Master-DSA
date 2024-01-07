#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter t=a number";
    cin>>n;
    int sum=0,lastdigit;
    while(n>0){
        lastdigit = n%10;
        sum = sum+lastdigit;
        n = n/10;
    }cout<<"Sum : "<<sum;
}