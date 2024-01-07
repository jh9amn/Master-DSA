#include<iostream>
using namespace std;
int main(){
    int a;
     cout<<"enter a number";
    cin>>a;

    if(a%3==0){
        if(a%5==0){
            cout<<"divisible by 3 and 5";
        }
    } else
    {
        cout<<"not divisible by 3 and 5";
    }
}