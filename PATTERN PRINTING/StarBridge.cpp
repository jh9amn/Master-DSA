// *******************
// ********* *********
// ********   ********
// *******     *******
// ******       ******
// *****         *****
// ****           ****
// ***             ***
// **               **
// *                 *


#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a Number";
    cin>>n;
   
   // this loop is for print the uppermost star pattern  (upto (n-1))
      for(int i=1; i<=2*n-1; i++){
        cout<<"*";
      } 
      cout<<endl;

     int m = n-1;
    int nsp = 1;
  
  // this loop for right side of triangle
    for(int i=1; i<=m; i++){
      //Star
      for(int j=1; j<=m+1-i; j++){
            cout<<"*";
      }

      //this loop is for spaces 
      for(int k=1; k<=nsp; k++){
        cout<<" ";
      }
      //star
      nsp+=2;

    // this loop is for again right side of triangle
      for(int j=1; j<=m+1-i; j++){
        cout<<"*";
      }
      cout<<endl;
    }
       
}