#include<iostream>
using namespace std;
int  main(){
    cout<<"enter the cost price :";
    int cp;
    cin>>cp;
    cout<<"enter the selling price :";
    int sp;
    cin>>sp;

    if(sp>cp){
        cout<<"profit = "<<sp-cp;
    }
   if(cp>sp) {
        cout<<"Loss = "<<cp-sp;
    }
    if(sp==cp){
        cout<<"NO PRofit ,No LOss !";
    }

}