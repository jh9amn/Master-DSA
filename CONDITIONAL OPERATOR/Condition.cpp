// Divisible by 3 or 5 but not by 15..
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"entre a number";
    cin>>n;
    
    if((n%3==0 || n%5==0) && (n%15!=0)){
            cout<<"number is divisible by 3 or 5 but not by 15";
    }
    else{
        cout<<"not matching condition";
    }
    return 0;
    
}
