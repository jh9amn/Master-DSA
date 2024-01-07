// *        *
//  *      *
//   *    *
//    *  *
//     **
//     **
//    *  *
//   *    *
//  *      *
// *        *


#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the size";
cin>>n;
for(int i=0; i<=n; i++){
    for(int j=1; j<=n; j++){
        if(i==j || i+j==n+1){
            cout<<"*";
        }else{ 
            cout<<" ";
        }
    } cout<<endl;
}
}