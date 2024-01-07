/*WAP tp check the number is prime or not*/
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the NUmber";
    cin>>a;
    bool flag = true; //true means prime
    for(int i=2; i<a;i++){
        if(a%i==0){
            flag = false;
            // cout<<"Composite Number";
            break;
        }
    }
    if(a==1)  cout<<"1 is neither prime nor composite";
    else if (flag == true)  cout<<a<<" "<<"is prime";
    else  cout<<a<<" "<<"is composite";
}