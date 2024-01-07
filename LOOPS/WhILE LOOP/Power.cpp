#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the Base value";
    cin>>a;
    cout<<"Enter the Exponent value";
    cin>>b;
    bool flag = true;
    float power=1;

if(b<0){
    flag = false;
    b = -b;
}

    for(int i=1; i<=b; i++){
        power = power * a;
    }

    if(flag==false){
        power = 1/power;
        b = -b;
    }
    
    if(a==0 && b==0){
        cout<<"Not Defined";
    }

    else{
        cout<<a<<" to the power "<<b<<" is "<<power;
    }
}


/*
 **********
 ****  ****
 ***    ***
 **      **
 *        *     
      
      */
