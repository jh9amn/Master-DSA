#include<iostream>
using namespace std;
int main(){
    int number;
    cout<<"enter a number";
    cin>>number;

    if(number>=100 && number<=999){
        cout<<"three digit number";
    }
    else {
        cout<<"not a three digit number";
    }
}