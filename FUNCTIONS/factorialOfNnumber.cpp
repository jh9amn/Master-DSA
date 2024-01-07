#include<iostream>
using namespace std;
int factorial(int n){
    int fact = 1;
    for(int i=2 ; i<=n; i++){
        fact *= i;
    } cout<<endl;
    return fact;
}
int main(){
    int n;
    cout<<"Enter the Value of N";
    cin>>n;
    for(int i=1; i<=n; i++)
{
    cout<<factorial(i);
}
return 0;
}