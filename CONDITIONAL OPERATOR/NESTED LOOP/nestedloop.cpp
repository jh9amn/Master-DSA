#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a  number";
    cin>>n;

    if((n%3==0 || n%5==0) ){
        if(n%15==0){
            cout<<"Number divisible by 3 or 5 but not 15";
        }
    }
    else {
        cout<<"not matching condition";
    }
    return 0;

}